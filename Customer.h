/**
   * Customer
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class represents a Customer
**/

#pragma once
#include "ListItem.h"

class Customer: public ListItem{
private:
    static int assigned_number;

    const int BIG_TIME;
    const int SMALL_TIME;
    const int FORV_TIME;
    const int COUPON_TIME;

    int big_items;
    int small_items;
    int forv_items;
    int coupon_items;

    int customer_number;
    int arrival_time;
    int completion_time;
    int wait_time;

public:
    Customer();
    ~Customer();

    void print() override;
    int compareTo(ListItem *item) override;

    void set_big(int);
    void set_small(int);
    void set_forv(int);
    void set_coupon(int);

    int get_service_time();
    int get_number();
    int get_arrival_time();
    int get_completion_time();
    int get_wait_time();
    int get_total_items();

    void set_arrival_time(int);
    void set_completion_time(int);
    void set_wait_time(int);
};



