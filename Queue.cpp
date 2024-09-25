/**
   * Queue
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class is a subclass of the GenericQueue, but the enqueue is overridden.
   * this just adds the element at the end of the queue. Follows FIFO principle.
**/
#include "Queue.h"
//this just adds the element at the end of the queue. Follows FIFO principle.
void Queue::enqueue(ListItem *item)
{
   if(top == nullptr)
   {
       top = new Node(item);
       bottom = top;
   }
   else
   {
       bottom->set_next(new Node(item));
       bottom = bottom->get_next();
   }
}

