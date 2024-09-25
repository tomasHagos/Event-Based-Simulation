/**
   * Event
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class is an abstract class. It is the parent class or
   *            arrivalEvent,StartServiceEvent,CompleteServiceEvent
**/

#include "Event.h"

Event::Event(Customer* customer1, int time1): customer(customer1), time(time1) {}

//this method compares two events based on time.
//if their time is equal, it compares them by customer number.
int Event::compareTo(ListItem *item)
{
    Event* other = dynamic_cast<Event*>(item);
    int returned = 0;

    if(other != nullptr)
    {
        if(time == other->time)
        {
            //compare by customer number.
            returned =  customer->compareTo(other->customer);
        }
        else if(time > other->time)
        {
            returned = 1;
        }
        else
        {
            returned = -1;
        }
    }
    return returned;
}

int Event::get_time()
{
    return time;
}

void Event::print()
{

}

Customer* Event::get_customer()
{
    return customer;
}

//leaving it empty as we are not deleting anything here.
// no memory was allocated in this object.
 Event::~Event(){}
