#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"
#include "login.h"
#include "in_login.h"
#include "sign_up.h"
using namespace std;



void checkbalance(User users[], int userIdx) {
    int choice;
    char again;

    do {
        cout << "\n================================" << endl;
        cout << "         ACCOUNT BALANCES       " << endl;
        cout << "================================" << endl;


        cout << "Select an account to check:" << endl;
        for (int i = 0; i < 3; i++) {
            if (!users[userIdx].accounts[i].bank_name.empty()) {
                cout << i + 1 << ". " << users[userIdx].accounts[i].bank_name << endl; //3ashan ybin kol el accounts
            }
        }

        cout << "\nYour choice: ";
        cin >> choice;

        int index = choice - 1; // 3ashan zero based

        if (index >= 0 && index < 3 && !users[userIdx].accounts[index].bank_name.empty()) {
            cout << "------------------------------------------" << endl;
            cout << "Account Holder:  " << users[userIdx].accounts[index].holder_name << endl;
            cout << "Bank:            " << users[userIdx].accounts[index].bank_name << endl;
            cout << "Current Balance: " << users[userIdx].accounts[index].balance << " EGP" << endl;
            cout << "------------------------------------------" << endl;
        }
        else {
            cout << "\n[!] INVALID ACCOUNT SELECTION" << endl;
        }

        cout << "Do you want to check another account? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');
}