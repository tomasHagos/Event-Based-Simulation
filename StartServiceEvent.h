/**
   * StartServiceEvent
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This is a class that represents the start service event.
**/
#pragma once
#include "Event.h"
#include "CheckoutLane.h"

class StartServiceEvent: public Event{
   private:
        CheckoutLane* lane; //holds the lane where the customer will be serviced
    public:
        StartServiceEvent(Customer*,int,CheckoutLane*);
        ~StartServiceEvent();
        CheckoutLane* get_lane();
        void print() override;


};


