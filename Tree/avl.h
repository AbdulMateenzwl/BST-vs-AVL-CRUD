#pragma once
#include "tree1.h"

class avl : public tree
{
public:
    void add_node(person* node);
    bool delete_node_with_rotation(int index);
    stack<person*> delete_node(person* node);
    int height(person* p);
    int getBalanceFactor(person* node);
    int max(int a, int b);
    stack<person*> insert(person* node);
    person* rightRotate(person* x);
    person* leftRotate(person* x);
    void rotate(stack<person*> s, person* node);
};