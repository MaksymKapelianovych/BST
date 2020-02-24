#include "tree.h"
#include "node.h"
#include "color.h"
#include <iostream>
Tree::Tree():root(nullptr){}
Tree::~Tree(){
    delete root;
}

void Tree::rotate_left(Node *n)
{
    Node *pivot = n->right;

    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
        if (n->parent->left==n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }else{
        root = pivot;
    }

    n->right = pivot->left;
    if (pivot->left != nullptr)
        pivot->left->parent = n;

    n->parent = pivot;
    pivot->left = n;
}

void Tree::rotate_right(Node *n)
{
    Node *pivot = n->left;

    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
        if (n->parent->left==n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }else{
        root = pivot;
    }

    n->left = pivot->right;
    if (pivot->right != nullptr)
        pivot->right->parent = n;

    n->parent = pivot;
    pivot->right = n;
}

void Tree::insert(int v)
{
    if(!root){
        root = new Node(v, nullptr);
        root->color = BLACK;
        return;
    }
    Node *x = root, *p = nullptr;
    while(x){
        if(x->value > v){
            p = x;
            x = x->left;
        }else if(x->value < v){
            p = x;
            x = x->right;
        }else{
            return;
        }
    }

    x = new Node(v, p);
    if(p->value > v){
        p->left = x;
    }else if(p->value < v){
        p->right = x;
    }
    insert_case1(x);

}

void Tree::insert_case1(Node *n)
{
    if (n->parent == nullptr)
        n->color = BLACK;
    else
        insert_case2(n);
}

void Tree::insert_case2(Node *n)
{
    if (n->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}

void Tree::insert_case3(Node *n)
{
    Node *u = n->uncle(), *g;

    if ((u != NULL) && (u->color == RED)) {
    // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
        n->parent->color = BLACK;
        u->color = BLACK;
        g = n->grandparent();
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}

void Tree::insert_case4(Node* n)
{
    Node *g = n->grandparent();

    if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);
        n = n->left;
    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case5(n);
}

void Tree::insert_case5(Node* n)
{
    Node *g = n->grandparent();

    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left)) {
        rotate_right(g);
    } else { /* (n == n->parent->right) && (n->parent == g->right) */
        rotate_left(g);
    }
}

void Tree::print(Node* n)
{
    if(n){
        print(n->left);
        std::cout << n->value << " ";
        print(n->right);
    }
}
