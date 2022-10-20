#include "avl.h"



void avl::add_node(person* node)
{
    stack<person*> s = insert(node);
    rotate(s, node);
}
bool avl::delete_node_with_rotation(int index)
{
    person* p = search(index);
    if (p == NULL)
    {
        return false;
    }
    stack<person*> s = delete_node(p);
    if (s.size() > 1)
    {
        person* p = s.top();
        s.pop();
        rotate(s, p);
    }
    return true;
}
stack<person*> avl::delete_node(person* node)
{
    stack<person*> s;
    person* prev = head;
    person* next = head;
    while (next != NULL && next->index != node->index)
    {
        prev = next;
        s.push(next);
        if (node->index < prev->index)
            next = prev->left;
        else
            next = prev->right;
    }
    if (next == NULL)
    {
        return s;
    }
    else if (next->left == NULL && next->right == NULL)
    {
        if (next == prev->left)
        {
            prev->left = NULL;
        }
        else
        {
            prev->right = NULL;
        }
        delete next;
        s.push(prev);
        return s;
    }
    else if (next->left == NULL || next->right == NULL)
    {
        person* newCurr;
        if (next->left == NULL)
        {
            newCurr = next->right;
        }
        else
        {
            newCurr = next->left;
        }
        if (prev == head)
        {
            delete next;
            head = newCurr;
            s.push(prev);
            return s;
        }
        if (next == prev->left)
        {
            prev->left = newCurr;
        }
        else
        {
            prev->right = newCurr;
        }
        delete next;
    }
    else
    {
        person* p = NULL;
        person* temp;
        temp = next->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
            p->left = temp->right;
        else
            next->right = temp->right;
        next->index = temp->index;
        delete temp;
    }
    s.push(prev);
    return s;
}
int avl::height(person* p)
{
    if (p == NULL)
        return 0;
    return p->height;
}
int avl::getBalanceFactor(person* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
int avl::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
stack<person*> avl::insert(person* node)
{
    stack<person*> s;
    if (head == NULL)
    {
        head = node;
        return s;
    }
    person* prev = head;
    person* next = head;
    while (next != NULL)
    {
        prev = next;
        s.push(next);
        if (node->index < prev->index)
        {
            next = prev->left;
        }
        else
        {
            next = prev->right;
        }
    }
    s.push(node);
    if (node->index >= prev->index)
    {
        prev->right = node;
    }
    else
    {
        prev->left = node;
    }
    return s;
}
person* avl::rightRotate(person* x)
{
    person* y = x->left;
    person* T2 = y->right;
    y->right = x;
    x->left = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
person* avl::leftRotate(person* x)
{
    person* y = x->right;
    person* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
void avl::rotate(stack<person*> s, person* node)
{
    person* temp;
    person* temp1=NULL;
    while (!s.empty())
    {
        temp = s.top();
        bool isBalanceChanged = false;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        int balanceFactor = getBalanceFactor(temp);
        if (balanceFactor > 1)
        {
            if (node->index < temp->left->index)
                temp1 = rightRotate(temp);
            else if (node->index > temp->left->index)
            {
                temp->left = leftRotate(temp->left);
                temp1 = rightRotate(temp);
            }
            isBalanceChanged = true;
        }
        if (balanceFactor < -1)
        {
            if (node->index > temp->right->index)
                temp1 = leftRotate(temp);
            else if (node->index < temp->right->index)
            {
                temp->right = rightRotate(temp->right);
                temp1 = leftRotate(temp);
            }
            isBalanceChanged = true;
        }
        s.pop();
        if (isBalanceChanged)
        {
            if (s.empty())
                head = temp1;
            else
            {
                if (s.top()->left == temp)
                    s.top()->left = temp1;
                else
                    s.top()->right = temp1;
            }
        }
    }
}
