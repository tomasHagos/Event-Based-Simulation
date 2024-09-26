/**
   * ExpressLaneSimulation
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents the Express Lane simulation
**/

#include "ExpressLaneSimulation.h"
#include "Queue.h"
#include "StartServiceEvent.h"
#include "CompleteServiceEvent.h"

ExpressLaneSimulation::ExpressLaneSimulation(fstream& file): Simulation(file)
{
    express_lane = new CheckoutLane("Express lane");
    regular_lane = new CheckoutLane("Regular lane");

    express_queue = new Queue();
}

ExpressLaneSimulation::~ExpressLaneSimulation()
{
    delete express_queue;
    delete regular_lane;
    delete express_lane;
}


void ExpressLaneSimulation::run_simulation()
{
    cout << "Simulation begins..." << endl;

    read_event_from_file();

    while(!event_list_empty())
    {
        //remove the first event and process it.
        process_event(remove_first_event());
    }

    //after simulation is done. print summary
    print_summary();
}

void ExpressLaneSimulation::process_event(Event* event)
{
    //firstly figure out what time of event we have.
    //we use dynamic cast.
    //and process the events accordingly.

    if(dynamic_cast<ArrivalEvent*>(event) != nullptr)
    {
        process_arrival_event(dynamic_cast<ArrivalEvent*>(event));
    }
    else if(dynamic_cast<StartServiceEvent*>(event) != nullptr)
    {
       process_start_service(dynamic_cast<StartServiceEvent*>(event));
    }
    else if(dynamic_cast<CompleteServiceEvent*>(event) != nullptr)
    {
        process_complete_service(dynamic_cast<CompleteServiceEvent*>(event));
    }

}

void ExpressLaneSimulation::process_arrival_event(ArrivalEvent* arrival)
{
    //print arrival
    arrival->print();

    Customer* customer = arrival->get_customer();

    //<=12 items is an express lane customer
    if(customer->get_total_items() <= 12)
    {
        //if queue is empty and express lane is available
        if(express_queue->isEmpty() && express_lane->get_availability())
        {
            schedule_start_service(customer,express_lane,arrival->get_time());
        }
        else
        {
            //otherwise the customer waits for their turn
            express_queue->enqueue(customer);
        }
    }
    else
    {
        //if regular queue is empty and regular lane is available.
        //schedule a start service.
        if(regular_waiting_line_empty() && regular_lane->get_availability())
        {
            schedule_start_service(customer,regular_lane,arrival->get_time());
        }
        else
        {
            //otherwise add the customer to the regular waiting queue
            add_customer_to_queue(customer);
        }
    }

    //if there is more event, read
    read_event_from_file();
    //delete the processed arrival.
    delete arrival;
}


void ExpressLaneSimulation::process_complete_service(CompleteServiceEvent* complete_service)
{
    //print the event
    complete_service->print();

    Customer* customer = complete_service->get_customer();


    CheckoutLane* lane = complete_service->get_lane();

    lane->set_customer(nullptr); //remove the customer from the lane
    lane->set_availability(true); //make the lane available for use

    //if the current lane was an express. Get the next customer from the express queue
    if(lane->get_lane_type() == "Express lane")
    {
        if(!express_queue->isEmpty())
        {
            Customer* first_customer = dynamic_cast<Customer*>(express_queue->front());

            schedule_start_service(first_customer,lane,complete_service->get_time());

            //remove the customer from the express lane
             express_queue->dequeue();
        }
    }
    else
    {
        //otherwise work with the regular queue
        if(!regular_waiting_line_empty())
        {
            schedule_start_service(get_first_customer(),lane,complete_service->get_time());
            //remove the customer from the waiting queue
            remove_first_customer();
        }
    }

    //delete the customer.
    delete customer;

    //delete the complete service event
    delete complete_service;
}
