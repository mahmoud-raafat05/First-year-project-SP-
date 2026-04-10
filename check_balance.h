#pragma once
#include <iostream>
#include <string>
using namespace std;

void checkBalance(User& currentUser) {
    int choice;
    char again;

    do {
        cout << "\n================================" << endl;
        cout << "         ACCOUNT BALANCES       " << endl;
        cout << "================================" << endl;

        // 1. Show the user WHICH accounts they actually have
        cout << "Select an account to check:" << endl;
        for (int i = 0; i < 3; i++) {
            // Only show slots that have a bank name (not empty)
            if (!currentUser.accounts[i].bankName.empty()) {
                cout << i + 1 << ". " << currentUser.accounts[i].bankName << endl;
            }
        }

        cout << "\nYour choice: ";
        cin >> choice;

        // 2. Validate using index (choice - 1)
        int index = choice - 1;

        if (index >= 0 && index < 3 && !currentUser.accounts[index].bankName.empty()) {
            cout << "------------------------------------------" << endl;
            cout << "Account Holder:  " << currentUser.accounts[index].holderName << endl;
            cout << "Bank:            " << currentUser.accounts[index].bankName << endl;
            cout << "Current Balance: " << currentUser.accounts[index].balance << " EGP" << endl;
            cout << "------------------------------------------" << endl;
        }
        else {
            cout << "\n[!] INVALID ACCOUNT SELECTION" << endl;
        }

        cout << "Do you want to check another account? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');
}
