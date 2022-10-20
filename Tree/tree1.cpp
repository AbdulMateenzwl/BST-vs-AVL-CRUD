
#include "tree1.h"

void tree::display_single(person* record)
{
    if (record == NULL)
    {
        cout << "There is no record of this Person . . ." << endl;
    }
    else
    {
        cout << "Persons details>>> " << endl
            << endl;
        cout << "index : " << record->index << endl;
        cout << "Customer ID : " << record->customer_id << endl;
        cout << "First name : " << record->first_name << endl;
        cout << "Last name : " << record->last_name << endl;
        cout << "Company : " << record->company << endl;
        cout << "City : " << record->city << endl;
        cout << "Country : " << record->country << endl;
        cout << "Phone 1 :" << record->phone_1 << endl;
        cout << "Phone 2 :" << record->phone_2 << endl;
        cout << "Email : " << record->email << endl;
        cout << "Subscription Date : " << record->subscription_date << endl;
        cout << "Website : " << record->website << endl;
    }
}
person* tree::search(int index)
{
    person* start = new person;
    start = head;
    if (start == NULL)
        return NULL;

    while (true)
    {
        if (start->index == index)
        {
            return start;
        }
        else if (start->index < index)
        {
            if (start->right == NULL)
            {
                return NULL;
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
                return NULL;
            }
            else
            {
                start = start->left;
            }
        }
    }
}
void tree::update(person* p1, person* p2)
{
    if (p1 == NULL)
    {
        cout << "Record of this person does not exists . . ." << endl;
    }
    else
    {
        p1->customer_id = p2->customer_id;
        p1->first_name = p2->first_name;
        p1->last_name = p2->last_name;
        p1->company = p2->company;
        p1->city = p2->city;
        p1->country = p2->country;
        p1->phone_1 = p2->phone_1;
        p1->phone_2 = p2->phone_2;
        p1->email = p2->email;
        p1->subscription_date = p2->subscription_date;
        p1->website = p2->website;
    }
}
void tree::preOrderTraversal(person* root)
{
    stack<person*> stk;
    if (root == NULL)
    {
        cout << "There is nothing to display" << endl;
    }
    stk.push(root);
    while (!stk.empty())
    {
        person* current = stk.top();
        stk.pop();
        display_single(current);
        if (current->right != NULL)
        {
            stk.push(current->right);
        }
        if (current->left != NULL)
        {
            stk.push(current->left);
        }
    }
}
void tree::inorderTraversal(person* root)
{
    if (root == NULL)
    {
        cout << "There is no data to display . . ." << endl;
    }
    stack<person*> stack;
    person* curr = root;
    vector<int> vtr;
    while (!stack.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stack.top();
            stack.pop();
            display_single(curr);
            curr = curr->right;
        }
    }
}
void tree::postorderTraversal(person* root)
{
    stack<person*> stk;
    vector<int> vtr;
    stack<person*> stk2;
    if (root == NULL)
    {
        cout << "There is no data to display . . . " << endl;
    }
    stk.push(root);
    while (!stk.empty())
    {
        person* current = stk.top();
        stk.pop();
        stk2.push(current);
        if (current->left != NULL)
        {
            stk.push(current->left);
        }
        if (current->right != NULL)
        {
            stk.push(current->right);
        }
    }
    while (!stk2.empty())
    {
        display_single(stk2.top());
        stk2.pop();
    }
}
void tree::bfs(person* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
    }
    queue<person*> q;
    q.push(root);
    while (!q.empty())
    {
        person* temp = q.front();
        display_single(q.front());
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}