#pragma once
#include <iostream>
using namespace std;
#include <string>
void login() {
	string username, password;
	cout << "please enter your username: ";
	getline(cin, username); // to read the username with spaces
	cout << "please enter your password: ";
	cin >> password;

	for (int i = 0; i < 10; i++) {
		if (users[i].username == username && users[i].password == password) {
			cout << "login successful!" << endl;
			 
		}
	}
}
