#include "node.h"
Node::Node(int v, Node *p):value(v), parent(p), color(RED), left(nullptr), right(nullptr){}

Node* Node::grandparent()
{
    if ((parent != nullptr))
        return parent->parent;
    else
        return nullptr;
}

Node * Node::uncle()
{
    Node *g = grandparent();
    if (g == nullptr)
        return nullptr;
    if (parent == g->left)
        return g->right;
    else
        return g->left;
}
