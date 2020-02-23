#ifndef NODE_H
#define NODE_H

#include "color.h"

class Node{
public:
    Node *parent = nullptr, *left = nullptr, *right = nullptr;
    Color color;
    int value;

    Node(int v, Node* p);

    Node *grandparent();
    Node *uncle();
};


#endif // NODE_H
