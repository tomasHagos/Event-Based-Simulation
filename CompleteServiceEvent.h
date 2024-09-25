/**
   * CompleteServiceEvent
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents a complete Service Event
**/
#pragma once
#include "Event.h"
#include "CheckoutLane.h"

class CompleteServiceEvent: public Event{
    private:
        CheckoutLane* lane; //represents the lane the customer is currently at.
    public:
        CompleteServiceEvent(Customer*, CheckoutLane*, int);
        ~CompleteServiceEvent();
        CheckoutLane* get_lane();
        void print() override;

};



