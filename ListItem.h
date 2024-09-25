/**
   * ListItem
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class is an abstract class. It is used for polymorphism purposes.
**/
#pragma once
class ListItem {
    public:
        virtual void print() =0;
        //abstract method that is invoked when we are comparing subclasses of ListItem.
        virtual int compareTo(ListItem *item) =0;

        virtual ~ListItem(); //virtual destructor


};


