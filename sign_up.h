#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"
#include "add_new_account.h"
#include <ctime>


using namespace std;

int signup(User users[], int& usercount) {
    if (usercount >= 9) {
        cout << "\n[!] Sorry, InstaPay is full, cannot add more users." << endl;
        return -1;
    }
    string new_user;
    cout << "\n=================================" << endl;
    cout << "          InstaPay Sign Up         " << endl;
    cout << "\n=================================" << endl;
    // 1. Validation for Username
    while (true) {
        cout << "Create Username: ";
        getline(cin >> ws, new_user);
        bool exists = false;
        for (int i = 0; i < usercount; i++) {
            if (users[i].username == new_user) {
                exists = true;
                break;
            }
        }
        if (exists) {
            cout << "[!] This username already exists. Try another one.\n";
        }
        else if (new_user.empty()) {
            cout << "[!] Username cannot be empty.\n";
        }
        else {
            users[usercount].username = new_user;
            break;
        }
    }
    // 2. Validation for Password
    while (true) {
        cout << "Create Password (min 4 chars): ";
        cin >> users[usercount].password;
        if (users[usercount].password.length() >= 4) {
            break;
        }
        cout << "[!] Password too short!\n";
    }
    // 3. Validation for Email
    while (true) {
        cout << "Enter Email Address: ";
        cin >> users[usercount].email;

        if (users[usercount].email.find('@') == -1) {
            cout << "[!] Invalid email. It must contain '@'.\n";
        }
        else {
            break;
        }
        
    }
    // 4. Validation for Phone
    while (true) {
        cout << "Enter Phone Number: ";
        cin >> users[usercount].phone;
        if (users[usercount].phone.length() >= 10) {
            break;
        }
        cout << "[!] Invalid phone number. Must be at least 10 digits.\n";
    }
    // ID before account creation
    users[usercount].id = usercount + 1;
	cout<<"User's ID = "<<users[usercount].id<<'\n';

	cout<<"----------------------------------------------";

    cout << "\n[+] Basic user information has been successfully recorded. Please proceed to enter your banking account details.\n";
    AddNewAccount(users, usercount);
    usercount++;
    cout << "\n[✔️] Registration completed successfully!\n";
    return 1;
}