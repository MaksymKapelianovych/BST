#ifndef TREE_H
#define TREE_H
class Node;

class Tree{
public:
    Node *root = nullptr;
    void insert(int v);
    void print(Node *n);
private:
    void insert_case1(Node *n);
    void insert_case2(Node *n);
    void insert_case3(Node *n);
    void insert_case4(Node *n);
    void insert_case5(Node *n);

    void rotate_left(Node *n);
    void rotate_right(Node *n);
};
#endif // TREE_H
