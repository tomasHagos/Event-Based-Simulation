/**
   * Node
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents a Node that stores a ListItem object.
**/
#include <iostream>
using namespace std;

#include "Node.h"

Node::Node(ListItem *item)
{
    this->item = item;
    next = nullptr;
}

void Node::set_next(Node *n)
{
    next = n;
}

Node *Node::get_next()
{
    return next;
}

ListItem* Node::get_item()
{
    return item;
}

void Node::print()
{
    item->print();

    if(next != nullptr)
    {
        next->print();
    }
}


Node::~Node(){}