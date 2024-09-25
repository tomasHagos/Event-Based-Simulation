/**
   *ArrivalEvent
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents an arrival event.
   */
#include <iostream>
using namespace std;

#include "ArrivalEvent.h"

ArrivalEvent::ArrivalEvent(Customer* customer1, int time1): Event(customer1,time1)
{
    //set the arrival time of the customer.
    customer1->set_arrival_time(time1);
}

//leaving it empty because we don't want to delete anything.
ArrivalEvent::~ArrivalEvent(){}

/**
       *  This method reads in the customer items from the file,
       * and updates the customer object
* */
void ArrivalEvent::read_in_items(string line, int i)
{
   string word;

   //this reads in the first letter, and skips the entire word by the number of letters
   //since we know what time of items is given in the file, we can do this.
   while(line[i] != '\0')
   {
       if(line[i] == 'C')
       {
           i = process_word(line,"COUPON",i+7);
       }
       else if(line[i]== 'F')
       {
           i = process_word(line,"FORV",i+5);
       }
       else if(line[i] == 'B')
       {
           i = process_word(line,"BIG",i+4);
       }
       else if(line[i] == 'S')
       {
           i = process_word(line,"SMALL",i+6);
       }

       //if we already reached the end of the string. Don't Increment.
       if(line[i] != '\0')
       {
           i++;
       }
   }

}

/**
    * This method is a helper method for the above.
 **/
int ArrivalEvent::process_word(string line, string word, int i)
{
  string number;
  int num;

  //get rid of extra spaces if there are any. For safety reasons
  //for example if it was like this SMALL   3
  while(line[i] == ' ')
  {
      i++;
  }

  while(line[i] != ' ' && line[i] != '\0')
  {
     number += line[i];
     i++;
  }

  //convert to int
  num = stoi(number);

  //set the item accordingly
  if(word == "SMALL")
  {
      get_customer()->set_small(num);
  }
  else if(word == "BIG")
  {
      get_customer()->set_big(num);
  }
  else if(word == "FORV")
  {
      get_customer()->set_forv(num);
  }
  else
  {
      get_customer()->set_coupon(num);
  }

  return i;
}

void ArrivalEvent::print()
{
  cout << "Time " << get_time() << ":";
  cout << " Customer " << get_customer()->get_number() <<" arrives:";
  get_customer()->print();
  cout << " Service time: " << get_customer()->get_service_time()<< endl;
}

