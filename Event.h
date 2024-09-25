/**
   * Event
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class is an abstract class. It is the parent class or
   *            arrivalEvent,StartServiceEvent,CompleteServiceEvent
**/

#pragma once
#include "ListItem.h"
#include "Customer.h"

class Event: public ListItem{
    private:
        Customer* customer;
        int time;
    public:
        Event(Customer*, int);

        virtual ~Event();

        void print() override;

        Customer* get_customer();

        int compareTo(ListItem *item) override;

        int get_time();


};



