/**
   * CheckoutLane
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents a checkout lane.
**/
#pragma once
#include <iostream>
using namespace std;

#include "Customer.h"

class CheckoutLane {
    private:
        bool available; //represents availability of the lane.
        Customer* customer;
        const string lane_type; //represents lane type. Express, regular ...
    public:
        explicit CheckoutLane(string);
        ~CheckoutLane();

        void set_customer(Customer*);
        void set_availability(bool);

        bool get_availability();
        string get_lane_type();

};



