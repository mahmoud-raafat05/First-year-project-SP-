#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"
using namespace std;

void checkBalance(User users[]) {
    int choice;
    char again;

    do {
        cout << "\n================================" << endl;
        cout << "         ACCOUNT BALANCES       " << endl;
        cout << "================================" << endl;

      
        cout << "Select an account to check:" << endl;
        for (int i = 0; i < 3; i++) {
            if (!users.accounts[i].bank_name.empty()) {
                cout << i + 1 << ". " << users.accounts[i].bank_name << endl;
            }
        }

        cout << "\nYour choice: ";
        cin >> choice;

        int index = choice - 1;

        if (index >= 0 && index < 3 && !User.accounts[index].bankName.empty()) {
            cout << "------------------------------------------" << endl;
            cout << "Account Holder:  " << User.accounts[index].holderName << endl;
            cout << "Bank:            " << User.accounts[index].bankName << endl;
            cout << "Current Balance: " << User.accounts[index].balance << " EGP" << endl;
            cout << "------------------------------------------" << endl;
        }
        else {
            cout << "\n[!] INVALID ACCOUNT SELECTION" << endl;
        }

        cout << "Do you want to check another account? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');
}




    