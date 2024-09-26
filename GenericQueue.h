/**
   * GenericQueue
   * @author Tomas Hagos
   *
   * REMARKS: This is a GenericQueue.
**/
#pragma once

#include "Node.h"

class GenericQueue{
    protected:
        Node* top;
        Node* bottom;

    public:
        virtual void enqueue(ListItem*) = 0;
        GenericQueue();
        ListItem* dequeue();
        virtual ~GenericQueue();

        void print();
        bool isEmpty();
        ListItem* front();

};


