/**
   * GenericQueue
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This is a GenericQueue.
**/
#include "GenericQueue.h"

GenericQueue::GenericQueue()
{
    top = nullptr;
    bottom = nullptr;
}


ListItem *GenericQueue::dequeue()
{
    ListItem* item = nullptr;

    if(top != nullptr)
    {
        item = top->get_item();

        Node *priorTop = top;

        top = top->get_next();

        //note we are not deleting the item inside the node.
        //Because we are returning it.
        delete priorTop;
    }
    else
    {
        bottom = nullptr;
    }


    return item;
}

ListItem* GenericQueue::front()
{
    return top->get_item();
}

void GenericQueue::print()
{
    if(top != nullptr)
    {
        top->print();
    }
}

bool GenericQueue::isEmpty()
{
    return top == nullptr;
}

//empty because no memory was allocated within this object.
GenericQueue::~GenericQueue(){}