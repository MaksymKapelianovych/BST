#ifndef NODE_H
#define NODE_H

#include "color.h"

class Node{
public:
    Node *parent, *left, *right;
    Color color;
    int value;

    Node(int v, Node* p);
    ~Node();

    Node *grandparent();
    Node *uncle();

private:

};


#endif // NODE_H
