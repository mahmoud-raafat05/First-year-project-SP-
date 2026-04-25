#pragma once
#include <iostream>
#include<string>
#include<cstdlib>
#include <ctime>
#include "all_structures.h"
using namespace std;

void signup(User users[],int& usercount) {
	
	if (usercount >= 9) {
		cout << "/n Sorry , InstaPay is full cannot add more users," << endl;
		return;
	}
	

	string new_user;
	bool exists = false;
	cout << "/n=================================" << endl;
	cout << "          InstaPay Sign Up         " << endl;
	cout << "/n=================================" << endl;

	cin.ignore();

	cout << "Creat Username:";
	getline(cin, new_user);

		for (int i = 0; i < usercount; i++) {
			if (users[i].username == new_user) {
				exists = true;
				break;
			}
		}
	if (exists) {
		cout << "[!] This username is already taken. Please try another one" << endl;
		return;
	}

	users[usercount].username = new_user;

	cout << "Create Password:";
	cin >> users[usercount].password;

	cout << "Enter Email Address:";
	cin >> users[usercount].email;

	cout << "Enter Phone Number:";
	cin >> users[usercount].phone;

	cout << "/n ---Bank Card Details---" << endl;

	cout << "1- Card Number:";
	cin >> users[usercount].accounts[0].card_number;

	cout << "2- Card Holder Name:";
	cin.ignore();
	getline(cin, users[usercount].accounts[0].holder_name);

	cout << "3- CVV Code:";
	cin >> users[usercount].accounts[0].cvv_code;

	cout << "4- Expiration Date (MM/YY):";
	cin >> users[usercount].accounts[0].expiration_date;

	cout << "5- Bank Name:";
	cin.ignore();
	getline(cin, users[usercount].accounts[0].bank_name);

	users[usercount].accounts[0].balance = (rand() % 3000) + 1046.579 ;

	users[usercount].id = usercount + 1;

	cout << " Account created succefully" << endl;
	cout << "Your  ID is :" << users[usercount].id << endl;


	cout << "===========================================" << endl;
	usercount++;


}
