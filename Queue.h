/**
   * Queue
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class is a subclass of the GenericQueue, but the enqueue is overridden.
   * this just adds the element at the end of the queue. Follows FIFO principle.
**/
#pragma once
#include "GenericQueue.h"

class Queue: public GenericQueue{
    public:
        void enqueue(ListItem*) override;

};



