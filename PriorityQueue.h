/**
   * PriorityQueue
   *
   * @author Tomas Hagos,
   *
   * REMARKS: This class is a subclass of the GenericQueue, but the enqueue is overridden.
**/
#pragma once
#include "GenericQueue.h"

class PriorityQueue: public GenericQueue{
    public:
        void enqueue(ListItem*) override;


};
