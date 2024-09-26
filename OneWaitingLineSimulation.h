/**
   * OneWaitingLineSimulation
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents the one waiting line simulation.
**/
#pragma once

#include "Simulation.h"
#include "Event.h"
#include "ArrivalEvent.h"
#include "CheckoutLane.h"
#include "StartServiceEvent.h"
#include "CompleteServiceEvent.h"

class OneWaitingLineSimulation: public Simulation{
   private:
    CheckoutLane* lane1;
    CheckoutLane* lane2;
    public:
        OneWaitingLineSimulation(fstream&);
        ~OneWaitingLineSimulation(); //this deletes lane1 and lane2

        void run_simulation() override;
        void process_event(Event*) override;

        void process_arrival_event(ArrivalEvent*);
        void process_complete_service(CompleteServiceEvent*);
        bool lane_available(); //returns a boolean on whether a lane is available


};



