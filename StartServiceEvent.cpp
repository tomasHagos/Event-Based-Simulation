/**
   * StartServiceEvent
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This is a class that represents the start service event.
**/
#include "StartServiceEvent.h"

StartServiceEvent::StartServiceEvent(Customer * customer1, int time,CheckoutLane* lane): Event(customer1,time)
{
    //wait time is: current time - arrival time.
    customer1->set_wait_time(time-customer1->get_arrival_time());
    this->lane = lane;
}

void StartServiceEvent::print()
{
    cout << "Time " << get_time() <<":";
    cout << " Customer " << get_customer()->get_number();
    cout << " begins service in " << lane->get_lane_type() << endl;
}


CheckoutLane* StartServiceEvent::get_lane()
{
    return lane;
}

//no memory allocated within this class
//so there is nothing to delete
StartServiceEvent::~StartServiceEvent(){}
