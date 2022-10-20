


#include <fstream>
#include <stack>
#include <conio.h>
#include <queue>
#include "bst.h"
#include "UI.h"
#include "avl.h"
#include "tree1.h"
#include<time.h>


using namespace std;
person* take_input(bool input = true)
{
	person* record = new person();
	cout << "Enter details>>> " << endl;
	if (input)
	{
		cout << "Enter the index : ";
		cin >> record->index;
	}
	cout << "Customer ID : ";
	cin >> record->customer_id;
	cout << "First name : ";
	cin >> record->first_name;
	cout << "Last name : ";
	cin >> record->last_name;
	cout << "Company : ";
	cin >> record->company;
	cout << "City : ";
	cin >> record->city;
	cout << "Country : ";
	cin >> record->country;
	cout << "Phone 1 :";
	cin >> record->phone_1;
	cout << "Phone 12 :";
	cin >> record->phone_2;
	cout << "Email : ";
	cin >> record->email;
	cout << "Subscription Date : ";
	cin >> record->subscription_date;
	cout << "Website : ";
	cin >> record->website;
	return record;
}
bool contains(string str, char ch)
{
	int i = 0;
	while (true)
	{
		if (str[i] == '\0')
		{
			break;
		}
		if (str[i] == ch)
		{
			return true;
		}
		i++;
	}
	return false;
}
string parse(string row, int column)
{

	int dollarCount = 1;
	string item;
	int index = 0;
	while (true)
	{
		char ch = row[index];
		if (ch == '\0')
			return item;
		if (ch == ',')
		{
			dollarCount++;
		}
		else if (dollarCount == column)
		{
			item = item + ch;
		}
		index++;
	}
	return item;
}
string parse_2(string row, int column)
{
	if (!contains(row, '"'))
	{
		return parse(row, 5);
	}
	int dollarCount = 0;
	string item;
	int index = 0;
	while (true)
	{
		char ch = row[index];
		if (ch == '\0')
			return item;
		if (ch == '"')
		{
			dollarCount++;
		}
		else if (dollarCount == column)
		{
			item = item + ch;
		}
		index++;
	}
	return item;
}
void continue_()
{
	system("pause");
}
void load_data_bst(string file, bst* data)
{
	clock_t start, end;
	start = clock();
	fstream show;
	show.open(file, ios::in);
	string str;
	getline(show, str);
	while (!show.eof())
	{
		person* record = new person();
		getline(show, str);
		if (str == "")
		{
			break;
		}
		record->index = stoi(parse(str, 1));
		record->customer_id = parse(str, 2);
		record->first_name = parse(str, 3);
		record->last_name = parse(str, 4);
		record->company = parse_2(str, 1);
		record->city = parse(str, 6);
		record->country = parse(str, 7);
		record->phone_1 = parse(str, 8);
		record->phone_2 = parse(str, 9);
		record->email = parse(str, 10);
		record->subscription_date = parse(str, 11);
		record->website = parse(str, 12);
		data->add_node(record);
	}
	show.close();
	end = clock();
	double db = double(end - start) / double(CLOCKS_PER_SEC);
	cout << db << "seconds" << endl;
	system("pause");
}
void load_data_avl(string file, avl* data)
{
	clock_t start, end;
	start = clock();
	fstream show;
	show.open(file, ios::in);
	string str;
	getline(show, str);
	while (!show.eof())
	{
		person* record = new person();
		getline(show, str);
		if (str == "")
		{
			break;
		}
		record->index = stoi(parse(str, 1));
		record->customer_id = parse(str, 2);
		record->first_name = parse(str, 3);
		record->last_name = parse(str, 4);
		record->company = parse_2(str, 1);
		record->city = parse(str, 6);
		record->country = parse(str, 7);
		record->phone_1 = parse(str, 8);
		record->phone_2 = parse(str, 9);
		record->email = parse(str, 10);
		record->subscription_date = parse(str, 11);
		record->website = parse(str, 12);
		data->add_node(record);
	}
	show.close();
	end = clock();
	double db = double(end - start) / double(CLOCKS_PER_SEC);
	cout << db << "seconds" << endl;
	system("pause");
}
void crud_bst(bst* data)
{
	while (true)
	{
		system("cls");
		char op = sub_menu_2();
		if (op == '1')
		{
			person* p = take_input();
			clock_t start, end;
			start = clock();
			data->add_node(p);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			system("pause");
		}
		else if (op == '2')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			data->display_single(data->search(index));
			continue_();
		}
		else if (op == '3')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			person* p = take_input(false);
			clock_t start, end;
			start = clock();
			data->update(data->search(index),p);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			system("pause");
		}
		else if (op == '4')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			clock_t start, end;
			start = clock();
			bool chk=data->delete_node(index);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			if (!chk)
			{
				cout << "There is no such data . . ." << endl;
			}
			else
			{
				cout << "Data has been deleted ." << endl;
			}
			system("pause");
		}
		else if (op == '5')
		{
			while (true)
			{
				char op1 = sub_menu_3();
				if (op1 == '1')
				{
					clock_t start, end;
					start = clock();
					system("pause");
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					data->inorderTraversal(data->head);
				}
				else if (op1 == '2')
				{
					clock_t start, end;
					start = clock();
					data->postorderTraversal(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else if (op1 == '3')
				{
					clock_t start, end;
					start = clock();
					data->preOrderTraversal(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else if (op1 == '4')
				{
					clock_t start, end;
					start = clock();
					data->bfs(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}
void crud_avl(avl* data)
{
	while (true)
	{
		system("cls");
		char op = sub_menu_2();
		if (op == '1')
		{
			person* p = take_input();
			clock_t start, end;
			start = clock();
			data->add_node(p);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			system("pause");
		}
		else if (op == '2')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			data->display_single(data->search(index));
			continue_();
		}
		else if (op == '3')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			clock_t start, end;
			person* p = take_input(false);
			start = clock();
			data->update(data->search(index),p);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			system("pause");
		}
		else if (op == '4')
		{
			int index;
			cout << "Enter the index : ";
			cin >> index;
			clock_t start, end;
			start = clock();
			bool chk=data->delete_node_with_rotation(index);
			end = clock();
			double db = double(end - start) / double(CLOCKS_PER_SEC);
			cout << db << "seconds" << endl;
			if (!chk)
			{
				cout << "There is no such data . . ." << endl;
			}
			else
			{
				cout << "Data has been deleted ." << endl;
			}
			system("pause");
		}
		else if (op == '5')
		{
			while (true)
			{
				char op1 = sub_menu_3();
				if (op1 == '1')
				{
					clock_t start, end;
					start = clock();
					data->inorderTraversal(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else if (op1 == '2')
				{
					clock_t start, end;
					start = clock();
					data->postorderTraversal(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else if (op1 == '3')
				{
					clock_t start, end;
					start = clock();
					data->preOrderTraversal(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else if (op1 == '4')
				{
					clock_t start, end;
					start = clock();
					data->bfs(data->head);
					end = clock();
					double db = double(end - start) / double(CLOCKS_PER_SEC);
					cout << db << "seconds" << endl;
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	while (true)
	{
		char op = main_menu();
		if (op == '1')
		{
			while (true)
			{
				system("cls");
				char op2 = sub_menu_1();
				if (op2 == '1')
				{
					bst* ft = new bst();
					load_data_bst("customers-100.csv", ft);
					crud_bst(ft);
				}
				else if (op2 == '2')
				{
					bst* ft = new bst();
					load_data_bst("customers-1000.csv", ft);
					crud_bst(ft);
				}
				else if (op2 == '3')
				{
					bst* ft = new bst();
					load_data_bst("customers-10000.csv", ft);
					crud_bst(ft);
				}
				else if (op2 == '4')
				{
					bst* ft = new bst();
					load_data_bst("customers-100000.csv", ft);
					crud_bst(ft);
				}
				else
				{
					break;
				}
			}
		}
		else if (op == '2')
		{
			while (true)
			{
				system("cls");
				char op2 = sub_menu_1();
				avl* obj = new avl();
				if (op2 == '1')
				{
					avl* ft = new avl();
					load_data_avl("customers-100.csv", ft);
					crud_avl(ft);
				}
				else if (op2 == '2')
				{
					avl* ft = new avl();
					load_data_avl("customers-1000.csv", ft);
					crud_avl(ft);
				}
				else if (op2 == '3')
				{
					avl* ft = new avl();
					load_data_avl("customers-10000.csv", ft);
					crud_avl(ft);
				}
				else if (op2 == '4')
				{
					avl* ft = new avl();
					load_data_avl("customers-100000.csv", ft);
					crud_avl(ft);
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}