#pragma once
#include <iostream>
#include<string>
#include<cstdlib>
#include <ctime>
#include <limits>
#include "all_structures.h"
#include "add_new_account.h"
using namespace std;

int signup(User users[],int& usercount) {
	
	if (usercount >= 9) {
		cout << "\n Sorry , InstaPay is full cannot add more users," << endl;
		return -1;
	}
	
		string new_user;
		bool exists = false;
		int existingIndex = -1;
		cout << "\n=================================" << endl;
		cout << "          InstaPay Sign Up         " << endl;
		cout << "\n=================================" << endl;

		cout << "Creat Username:";
		getline(cin >> ws, new_user);
		if (new_user.empty()) {
			cout << "[!] Username cannot be empty.\n";
			return -1;
		}

		// Check if username already exists
		for (int i = 0; i < usercount; i++) {
			if (users[i].username == new_user) {
				exists = true;
				existingIndex = i;
				break;
			}
		}
		
		
		if (exists) {
			cout << "\n[!] This username already exists.\n";
			cout << "User details:\n";
			cout << "ID: " << users[existingIndex].id << endl;
			cout << "Username: " << users[existingIndex].username << endl;
			cout << "Email: " << users[existingIndex].email << endl;
			cout << "Phone: " << users[existingIndex].phone << endl;
			return -1;
		}

		
		users[usercount].username = new_user;

		cout << "Create Password:";
		cin >> users[usercount].password;
		if (users[usercount].password.length() < 4) {
			cout << "[!] Password must be at least 4 characters.\n";
			return -1;
		}

		cout << "Enter Email Address:";
		cin >> users[usercount].email;
		if (users[usercount].email.find('@') == string::npos) {
			cout << "[!] Invalid email. It must contain @\n";
			return -1;
		}

		cout << "Enter Phone Number:";
		cin >> users[usercount].phone;
		if (users[usercount].phone.length() < 10) {
			cout << "[!] Invalid phone number.\n";
			return -1;
		}

		
		users[usercount].id = usercount + 1;
		AddNewAccount(users, usercount);
		usercount++;
		return 1;  
}
