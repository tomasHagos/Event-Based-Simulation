/**
   * Customer
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents a Customer
**/

#include <iostream>
using namespace std;

#include "Customer.h"

//initialize the static variable to 1
int Customer::assigned_number = 1;

Customer::Customer(): customer_number(assigned_number),  BIG_TIME(2),
SMALL_TIME(1), FORV_TIME(4),
COUPON_TIME(5)
{
    //increment the assigned_number static variable
     assigned_number++;

     arrival_time = 0;
     wait_time = 0;
     big_items =0;
     small_items=0;
     forv_items =0;
     coupon_items = 0;
}


void Customer::print()
{
    if(small_items != 0)
    {
        cout << " SMALL: " << small_items;
    }
    if(big_items != 0)
    {
        cout << " BIG: " << big_items;
    }
    if(forv_items != 0)
    {
        cout << " FORV: " << forv_items;
    }
    if(coupon_items != 0)
    {
        cout << " COUPON: " << coupon_items;
    }
}

void Customer::set_arrival_time(int time)
{
    arrival_time = time;
}


void Customer::set_big(int big)
{
    big_items = big;
}

void Customer::set_small(int small)
{
    small_items = small;
}

void Customer::set_coupon(int coupon)
{
    coupon_items = coupon;
}

void Customer::set_forv(int forv)
{
    forv_items = forv;
}

int Customer::get_service_time()
{
    int service_time = (big_items * BIG_TIME) + (small_items * SMALL_TIME) + (forv_items*FORV_TIME)
                       +(coupon_items * COUPON_TIME);

    return service_time;
}
int Customer::compareTo(ListItem* item)
{
    int returned = 0;
    Customer* other = dynamic_cast<Customer*>(item);

    if(other != nullptr)
    {
        if(this->customer_number > other->customer_number)
        {
            returned = 1;
        }
        else if(this->customer_number < other->customer_number)
        {
            returned = -1;
        }
    }

    return returned;
}

int Customer::get_number()
{
    return customer_number;
}

int Customer::get_arrival_time()
{
    return arrival_time;
}

void Customer::set_wait_time(int time)
{
    wait_time = time;
}

int Customer::get_completion_time()
{
    return completion_time;
}

int Customer::get_wait_time()
{
    return wait_time;
}

void Customer::set_completion_time(int time)
{
    completion_time = time;
}

int Customer::get_total_items()
{
    return big_items+small_items+forv_items;
}

Customer::~Customer()
{

}
