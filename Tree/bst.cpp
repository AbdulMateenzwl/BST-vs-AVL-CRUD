#include "bst.h"
void bst::add_node(person* node)
{
    person* start = new person;
    start = head;
    if (head == NULL)
    {
        head = node;
        return;
    }
    while (true)
    {
        if (start->index <= node->index)
        {
            if (start->right == NULL)
            {
                start->right = node;
                return;
            }
            else
            {
                start = start->right;
            }
        }
        else
        {
            if (start->left == NULL)
            {
                start->left = node;
                return;
            }
            else
            {
                start = start->left;
            }
        }
    }
}
bool bst::delete_node(int index)
{
    person* prev = head;
    person* next = head;
    while (next != NULL && next->index != index)
    {
        prev = next;
        if (index < prev->index)
            next = prev->left;
        else
            next = prev->right;
    }
    if (next == NULL)
    {
        return false;
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
        return true;
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
            return true;
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
    return true;
}