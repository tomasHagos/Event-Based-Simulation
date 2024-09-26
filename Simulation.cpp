/**
   * Simulation
   *
   * @author Tomas Hagos
   *
   * REMARKS: This is an abstract class for the two types of the simulation.
**/

#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Customer.h"
#include "ArrivalEvent.h"
#include "CompleteServiceEvent.h"

Simulation::Simulation(fstream& file1): file(file1)
{
    event_list = new PriorityQueue(); //eventList is priorityQueue
    regular_waiting_queue = new Queue();
    total_customers = 0;
    total_service_time = 0;
    waiting_total = 0;
}

//destructor
Simulation::~Simulation()
{
    delete regular_waiting_queue;
    delete event_list;
}

void Simulation::read_event_from_file()
{
    if(file.is_open())
    {
        string line;
        string word;
        int time;

        bool time_read = false;
        bool confirmed = false;

        if(getline(file,line))
        {
            //create a new customer.
            Customer *new_customer = new Customer();

            int i=0;
            bool done = false;

            while(line[i] != '\0' && !done)
            {
                if(line[i] != ' ')
                {
                    word += line[i];
                }
                else
                {
                    if(!time_read)
                    {
                        if(!word.empty())
                        {
                            confirmed = true; //confirm we read the time
                            time = stoi(word);
                            time_read = true;
                        }
                        word.clear();
                    }
                    else
                    {
                        done = true;
                    }
                }
                i++;
            }

            if(confirmed)
            {
                //create the arrivalEvent
                ArrivalEvent *arrivalEvent = new ArrivalEvent(new_customer,time);

                increment_customer_number();
                //read in the customers items. Starting position is i.(index)
                arrivalEvent->read_in_items(line,i);
                //increment service time
                increment_service_time(arrivalEvent->get_customer()->get_service_time());
                //add the eventList to the queue
                event_list->enqueue(arrivalEvent);
            }

        }

    }
}

Event* Simulation::remove_first_event()
{
    ListItem* event = event_list->dequeue();

    return dynamic_cast<Event*>(event);
}

bool Simulation::event_list_empty()
{
    return event_list->isEmpty();
}

bool Simulation::regular_waiting_line_empty()
{
    return regular_waiting_queue->isEmpty();
}

void Simulation::process_start_service(StartServiceEvent* start_service)
{
    //print the start service event.
    start_service->print();

    Customer* customer = start_service->get_customer(); //get the customer
    int time = start_service->get_time();

    CheckoutLane* lane = start_service->get_lane(); //get the lane the customer is in


    lane->set_availability(false); //set the lane unavailable.
    lane->set_customer(start_service->get_customer()); //add the customer to the lane

    //increment the wait time
    increment_wait_time(customer->get_wait_time());

    //schedule a complete service event. time of start service + service time required.
    schedule_complete_service(customer,lane,customer->get_service_time()+time);

    //delete the start service.
    delete start_service;
}

void Simulation::schedule_start_service(Customer* customer, CheckoutLane* lane, int time)
{
    StartServiceEvent* start_service = new StartServiceEvent(customer,time,lane);
    event_list->enqueue(start_service);
}

void Simulation::schedule_complete_service(Customer *customer, CheckoutLane *lane, int time)
{
    CompleteServiceEvent* complete_service = new CompleteServiceEvent(customer, lane, time);
    event_list->enqueue(complete_service);
}

void Simulation::add_customer_to_queue(Customer * customer)
{
    regular_waiting_queue->enqueue(customer);
}

Customer* Simulation::remove_first_customer()
{
    return dynamic_cast<Customer*>(regular_waiting_queue->dequeue());
}

Customer* Simulation::get_first_customer()
{
    return dynamic_cast<Customer*>(regular_waiting_queue->front());
}
void Simulation::printEventList()
{
    event_list->print();
}

void Simulation::increment_customer_number()
{
    total_customers++;
}

void Simulation::increment_service_time(int num)
{
    total_service_time += num;
}

void Simulation::increment_wait_time(int num)
{
    waiting_total += num;
}

void Simulation::print_summary()
{
    double average_service_time = ((double)total_service_time) /total_customers;
    double average_waiting_time  = ((double)waiting_total)/ total_customers;
    cout << "###### Summary ######" << endl;
    cout << "- Total number of customers: " << total_customers << endl;

    cout << "- Service time: total = " << total_service_time << ", average = "
    << average_service_time << endl;

    cout << "- Waiting time: total = " << waiting_total <<", average = " << average_waiting_time << endl;

}

//used for testing purposes.
void Simulation::print_queue()
{
    regular_waiting_queue->print();
}

