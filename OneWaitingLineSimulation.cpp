/**
   * OneWaitingLineSimulation
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents the one waiting line simulation.
**/

#include "OneWaitingLineSimulation.h"

OneWaitingLineSimulation::OneWaitingLineSimulation(fstream& file) : Simulation(file)
{
    lane1 = new CheckoutLane("1st lane"); //give the lanes a name. for printing purposes.
    lane2 = new CheckoutLane("2nd lane");
}



OneWaitingLineSimulation::~OneWaitingLineSimulation()
{
    delete lane1;
    delete lane2;
}

void OneWaitingLineSimulation::run_simulation()
{
    cout << "Simulation begins..." << endl;
    read_event_from_file();

    while(!event_list_empty())
    {
        process_event(remove_first_event());
    }

    //after simulation is done. print summary
    print_summary();

}

void OneWaitingLineSimulation::process_event(Event* event)
{
    //first figure out what type of event we are working with.
    //and process the event accordingly.
    if(dynamic_cast<ArrivalEvent*>(event) != nullptr)
    {
        process_arrival_event(dynamic_cast<ArrivalEvent*>(event));
    }
    else if(dynamic_cast<StartServiceEvent*>(event) != nullptr)
    {
        //note this method is in the super class.
        process_start_service(dynamic_cast<StartServiceEvent*>(event));
    }
    else if(dynamic_cast<CompleteServiceEvent*>(event) != nullptr)
    {
        process_complete_service(dynamic_cast<CompleteServiceEvent*>(event));
    }

}

void OneWaitingLineSimulation::process_arrival_event(ArrivalEvent* arrival)
{
    //print the arrival.
    arrival->print();

    if(regular_waiting_line_empty() &&(lane_available()))//checkout lane empty.
    {
        if(lane1->get_availability())
        {
            //if lane1 is available schedule a start service event based on lane1
            schedule_start_service(arrival->get_customer(),lane1,arrival->get_time());
        }
        else
        {
            schedule_start_service(arrival->get_customer(),lane2,arrival->get_time());
        }
    }
    else //add them to the waiting queue.
    {
        add_customer_to_queue(arrival->get_customer());
    }

    //if there is more event, read
    read_event_from_file();
    //delete the processed arrival.
    delete arrival;
}


void OneWaitingLineSimulation::process_complete_service(CompleteServiceEvent * complete_service)
{
    //print the event
    complete_service->print();
    //get the customer
    Customer* customer = complete_service->get_customer();

    //get the lane
    CheckoutLane* lane = complete_service->get_lane();

    //remove the customer from the lane and make the lane available.
    lane->set_customer(nullptr);
    lane->set_availability(true);

    //if there are more customers
    if(!regular_waiting_line_empty())
    {
        schedule_start_service(get_first_customer(),lane,complete_service->get_time());
        //remove the customer from the waiting queue
         remove_first_customer();
    }

    //delete the customer.
    delete customer;

    delete complete_service;

}

bool OneWaitingLineSimulation::lane_available()
{
    return lane1->get_availability() || lane2->get_availability();
}
