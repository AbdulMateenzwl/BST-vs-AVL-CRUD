#pragma once
#include "tree1.h"


using namespace std;
class bst : public tree
{
public:
    void add_node(person* node);
    bool delete_node(int index);
};

