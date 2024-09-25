/**
   * Node
   *
   * @author Tomas Hagos, 7969147
   *
   * REMARKS: This class represents a Node that stores a ListItem object.
**/
#pragma once
#include "ListItem.h"
class Node{

private:
    ListItem* item;
    Node* next;

public:
    Node(ListItem*);
    ~Node();

    Node* get_next();
    ListItem* get_item();

    void set_next(Node*);

    void print();
};




