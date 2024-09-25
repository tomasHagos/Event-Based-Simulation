/**
   * CheckoutLane
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents a checkout lane.
**/
#include "CheckoutLane.h"

CheckoutLane::CheckoutLane(string lane): lane_type(lane)
{
    available = true;
    customer = nullptr;
}

//leaving it empty as we are not deleting anything
CheckoutLane::~CheckoutLane(){}

void CheckoutLane::set_availability(bool isAvaliable)
{
    available = isAvaliable;
}

void CheckoutLane::set_customer(Customer * customer)
{
    this->customer = customer;
}

bool CheckoutLane::get_availability()
{
    return available;
}

string CheckoutLane::get_lane_type()
{
    return lane_type;
}