/**
   * PriorityQueue
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class is a subclass of the GenericQueue, but the enqueue is overridden.
**/
#pragma once
#include "GenericQueue.h"

class PriorityQueue: public GenericQueue{
    public:
        void enqueue(ListItem*) override;


};
