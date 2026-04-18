#pragma once
#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include<all_structures.h>

void signup() {

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
	getline(cin, new_user)

		for (int i = 0; i < userCount; i++) {
			if (User[i].username == new_user) {
				exists = true;
				break;
			}
		}
	if (exists) {
		cout << "[!] This username is already taken. Please try another one" << endl;
		return;
	}

	User[usercount].username = new_user;

	cout << "Create Password";
	cin >> User[usercount].password;

	cout << "Enter Email Address";
	cin >> User[usercount].email;

	cout << "Enter Phone Number";
	cin >> User[usercount].phone;

	cout << "/n ---Bank Card Details---" << endl;

	cout << "1- Card Number:";
	cin >> User[usercount].accounts[0].card_number;

	cout << "2- Card Holder Name:";
	cin.ignore();
	getline(cin, User[usercount].accounts[0].holder_name);

	cout << "3- CVV Code:";
	cin >> User[usercount].accounts[0].cvv_code;

	cout << "4- Expiration Date (MM/YY):";
	cin >> User[usercount].accounts[0].expiration_date;

	cout << "5- Bank Name:";
	cin >> User[usercount].accounts[0].bank_name;

	User[usercount].accounts[0].balance = 1000 + rand % 3000;

	User[usercount].id = usercount + 1;

	cout << " Account created succefully" << endl;
	cout << "Your  ID is :" << User[usercount].id << endl;

	usercount++;

	cout << "===========================================" << endl

}
