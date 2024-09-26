/**
   * PriorityQueue
   *
   * @author Tomas Hagos
   *
   * REMARKS: This class is a subclass of the GenericQueue, but the enqueue is overridden.
**/
#include "PriorityQueue.h"
void PriorityQueue::enqueue(ListItem *item)
{
    if(top != nullptr)
    {
        Node *prev = nullptr;
        Node *current = top;

        //while current is less than the item.
        while(current != nullptr && (current->get_item())->compareTo(item) < 0)
        {
            prev = current;
            current = current->get_next();
        }
        //first entry
        if(prev == nullptr)
        {
            top = new Node(item);
            top->set_next(current);
        }
        else
        {
            prev->set_next(new Node(item));
            prev->get_next()->set_next(current);
            //this means we added to the end of the linked list.
            if(current == nullptr)
            {
                bottom = prev->get_next();
            }
        }
    }
    else
    {
        //first entry
        top = new Node(item);
        bottom = top;
    }
}
