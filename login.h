#pragma once
#include <iostream>
#using namespace std;
#include <string>
int login() {
	string username, password;
	cout << "please enter your username: ";
	cin >> username;
	cout << "please enter your password: ";
	cin >> password;
	 
	for (int i = 0; i < 10; i++) {
		if (users[i].username == username && users[i].password == password) {
			cout << "login successful!" << endl;
			return i; // return the index of the logged-in user
		}
	}
}
