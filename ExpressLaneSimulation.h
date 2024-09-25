/**
   * ExpressLaneSimulation
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents the Express Lane simulation
**/
#pragma once

#include "Simulation.h"
#include "ArrivalEvent.h"
#include "StartServiceEvent.h"
#include "CompleteServiceEvent.h"

class ExpressLaneSimulation: public Simulation{
    private:
        CheckoutLane* express_lane;
        CheckoutLane* regular_lane;
        GenericQueue* express_queue; //queue for <=12 items.
        //the regular queue is in the super class.
    public:
         ExpressLaneSimulation(fstream&);
        ~ExpressLaneSimulation();

        void process_event(Event *) override;
        void run_simulation() override; //runs the simulation

        void process_arrival_event(ArrivalEvent*);
        void process_complete_service(CompleteServiceEvent*);


};

