#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "all_structures.h"

void login() {
	string username, password;
	cout << "please enter your username: ";
	cin.ignore();
	getline(cin, username); // to read the username with spaces

	cout << "please enter your password: ";

	cin >> password;

	bool found = false; // to check if user is found

	for (int i = 0; i < 10; i++) {

		if (users[i].username == username && users[i].password == password) {
			found = true;
			cout << "Login successful! Welcome, " << users[i].username << "." << endl;

			break;
		}


	}
	if (!found)
		cout << "Invalid username or password. Please try again." << endl;
}