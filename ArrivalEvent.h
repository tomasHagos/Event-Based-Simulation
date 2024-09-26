/**
   *ArrivalEvent
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents an arrival event.
   */
#pragma once
#include "Event.h"

class ArrivalEvent: public Event {
    public:
        ArrivalEvent(Customer*,int);
        ~ArrivalEvent(); // destructor
        void print() override;  //this method prints the arrival event

        /**
        *  This method reads in the customer items from the file,
        * and updates the customer object
        * @param string holds the line to be read
        * @param secondParameter is an integer that signifies where in
        *                      the string the reading
        *                       should begin.(index)
        */
        void read_in_items(string, int);

        int process_word(string,string, int); //this is a helper method for the method above

};



