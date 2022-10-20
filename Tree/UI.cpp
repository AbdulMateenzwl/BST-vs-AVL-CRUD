
#include "UI.h"
char main_menu()
{
    system("cls");
    cout << "_____________________  MAIN MENU  ________________________" << endl;
    cout << "1. Binary Search Tree" << endl;
    cout << "2. AVL Search Tree" << endl;
    cout << "3. EXIT" << endl;
    char op;
    cin >> op;
    return op;
}
char sub_menu_1()
{
    cout << "1. Load 100 Records" << endl;
    cout << "2. Load 1000 Records" << endl;
    cout << "3. Load 10000 Records" << endl;
    cout << "4. Load 100000 Records" << endl;
    cout << "5. Back" << endl;
    char op;
    cin >> op;
    return op;
}
char sub_menu_2()
{
    cout << "1. Insert a record" << endl;
    cout << "2. Retrive a record" << endl;
    cout << "3. Update a record" << endl;
    cout << "4. Delete a record" << endl;
    cout << "5. Traverse the Tree" << endl;
    cout << "6. Back" << endl;
    char op;
    cin >> op;
    return op;
}
char sub_menu_3()
{
    cout << "1. In Order Traversal" << endl;
    cout << "2. Post Order Traversal" << endl;
    cout << "3. Pre Order Traversal" << endl;
    cout << "4. Breath first Traverslal" << endl;
    cout << "5. EXIT" << endl;
    char op;
    cin >> op;
    return op;
}
