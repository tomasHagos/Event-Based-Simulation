/**
   * CompleteServiceEvent
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents a complete Service Event
**/
#include "CompleteServiceEvent.h"

CompleteServiceEvent::CompleteServiceEvent(Customer* customer, CheckoutLane* lane, int time): Event(customer, time)
{
    get_customer()->set_completion_time(time);
    this->lane = lane;
}

//leaving it empty here. We are not deleting anything inside.
//there was no memory allocated within this instance of a class
CompleteServiceEvent::~CompleteServiceEvent() {}

CheckoutLane* CompleteServiceEvent::get_lane()
{
    return lane;
}
void CompleteServiceEvent::print()
{
    cout << "Time " << get_time() <<":";
    cout << " Customer " << get_customer()->get_number();
    cout << " completes service in " << lane->get_lane_type() << ".";
    cout << " Arrival: " << get_customer()->get_arrival_time();
    cout <<" Complete: " << get_customer()->get_completion_time();
    cout <<" Wait: " << get_customer()->get_wait_time() << endl;
}


