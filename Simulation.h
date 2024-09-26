/**
   * Simulation
   *
   * @author Tomas Hagos
   * REMARKS: This is an abstract class for the two types of the simulation.
**/

#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "GenericQueue.h"
#include "Customer.h"
#include "Event.h"
#include "CheckoutLane.h"
#include "StartServiceEvent.h"

class Simulation{
    private:
        GenericQueue* regular_waiting_queue; //regular queue is in both types of sumulation.
        GenericQueue* event_list;
        fstream& file; //holds the file

        int total_customers; //also summarized data is put here.
        int total_service_time;
        int waiting_total;
    public:
        Simulation(fstream& file);
        virtual ~Simulation(); //deletes waiting queue and event list

        //pure virtual methods that makes this class abstract
        virtual void process_event(Event*) = 0;
        virtual void run_simulation() = 0;


        void increment_customer_number();
        void increment_service_time(int);
        void increment_wait_time(int);

        void read_event_from_file();
        Event* remove_first_event();
        Customer* remove_first_customer(); //this removes first customer from the waiting Queue

        void process_start_service(StartServiceEvent*); //used by both types of simulation

        void schedule_start_service(Customer*, CheckoutLane*, int);
        void schedule_complete_service(Customer*, CheckoutLane*, int);

        void add_customer_to_queue(Customer*);
        Customer* get_first_customer();

        bool event_list_empty();
        bool regular_waiting_line_empty(); //checks if the regular_waiting_line is empty

        void printEventList();
        void print_queue();

        void print_summary();
};



