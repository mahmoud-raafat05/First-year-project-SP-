#pragma once
#include <iostream>
#include <string>
using namespace std;

struct account{
    string card_number;
    string holder_name;
    string cvv_code;
    string expiration_date;
    string bank_name;
    double balance;

};

struct transaction{
    string from;
    string to;
    double amount;

};
struct User {
    int id;
    string username;
    string password;
    string email;
    string address;
    string phone;
    account accounts[3]; 
    transaction transactions[10];
};
