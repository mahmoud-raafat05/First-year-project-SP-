#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"

using namespace std;

extern User users[10];

void transfer(int currentUserIndex) {
    if (currentUserIndex == -1) return;

    string targetPhone;
    double amount;
    int accountChoice;

    cout << "\n--- Transfer Money ---" << endl;
    cout << "Choose the account to transfer from (1 or 2 or 3):" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "- Account: " << users[currentUserIndex].accounts[i].card_number
            << " [Balance: " << users[currentUserIndex].accounts[i].balance << "]" << endl;
    }

    cout << "Your choice: ";
    cin >> accountChoice;

    int fromAccIdx = accountChoice - 1;

    if (fromAccIdx < 0 || fromAccIdx > 2) {
        cout << "Invalid account choice!" << endl;
        return;
    }

    cout << "Enter Receiver Phone: ";
    cin >> targetPhone;

    if (targetPhone == users[currentUserIndex].phone) {
        cout << "Error: You cannot transfer money to your own phone number!" << endl;
        return;
    }

    int receiverIdx = -1;
    for (int i = 0; i < 10; i++) {
        if (users[i].phone == targetPhone) {
            receiverIdx = i;
            break;
        }
    }

    if (receiverIdx == -1) {
        cout << "User not found!" << endl;
        return;
    }

    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
        return;
    }

    if (users[currentUserIndex].accounts[fromAccIdx].balance >= amount) {
        users[currentUserIndex].accounts[fromAccIdx].balance -= amount;
        users[receiverIdx].accounts[0].balance += amount;

        cout << "Transfer Successful!" << endl;
        cout << "New balance for this account: " << users[currentUserIndex].accounts[fromAccIdx].balance << endl;

        users[currentUserIndex].transactions[0].from = users[currentUserIndex].username;
        users[currentUserIndex].transactions[0].to = users[receiverIdx].username;
        users[currentUserIndex].transactions[0].amount = amount;
    }
    else {
        cout << "Error: Insufficient balance." << endl;
    }
}