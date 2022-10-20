#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include "person.h"


using namespace std;
class tree
{
public:
    person* head;
    tree() { head = NULL; }
    person* search(int index);
    void update(person* p1, person* p2);
    void preOrderTraversal(person* root);
    void postorderTraversal(person* root);
    void inorderTraversal(person* root);
    void display_single(person* record);
    void bfs(person* root);
};
