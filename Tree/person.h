#pragma once
#include<iostream>
using namespace std;
struct person
{

    int index;
    string customer_id;
    string first_name;
    string last_name;
    string company;
    string city;
    string country;
    string phone_1;
    string phone_2;
    string email;
    string subscription_date;
    string website;
    int height = 1;
    person* left = NULL;
    person* right = NULL;
};
