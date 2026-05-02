#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"

using namespace std;

extern User users[10];

void transfer(int currentUserIndex) {
    if (currentUserIndex == -1) return;

    while (true) {
        string targetPhone;
        double amount;
        int senderAccountChoice;
        int receiverAccountChoice;

        cout << "\n--- Transfer Money ---" << endl;
        cout << "Select your account (1, 2, or 3) or 0 to go back: ";
        cin >> senderAccountChoice;

        if (senderAccountChoice == 0) return;

        int sAccIdx = senderAccountChoice - 1;
        if (sAccIdx < 0 || sAccIdx > 2 || users[currentUserIndex].accounts[sAccIdx].card_number == "") {
            cout << "Error: Your selected account does not exist. Please try again." << endl;
            continue;
        }

        cout << "Enter Receiver Phone (or 0 to cancel): ";
        cin >> targetPhone;

        if (targetPhone == "0") return;

        int receiverIdx = -1;
        for (int i = 0; i < 10; i++) {
            if (users[i].phone == targetPhone) {
                receiverIdx = i;
                break;
            }
        }

        if (receiverIdx == -1) {
            cout << "Error: Receiver phone number not found. Let's try again." << endl;
            continue;
        }

        cout << "Select receiver's account (1, 2, or 3) or 0 to cancel: ";
        cin >> receiverAccountChoice;

        if (receiverAccountChoice == 0) return;

        int rAccIdx = receiverAccountChoice - 1;
        if (rAccIdx < 0 || rAccIdx > 2 || users[receiverIdx].accounts[rAccIdx].card_number == "") {
            cout << "Error: This account does not exist for the receiver. Try again." << endl;
            continue;
        }

        cout << "Enter amount (or 0 to cancel): ";
        cin >> amount;

        if (amount == 0) return;
        if (amount < 0) {
            cout << "Invalid amount! Try again." << endl;
            continue;
        }

        if (users[currentUserIndex].accounts[sAccIdx].balance >= amount) {
            users[currentUserIndex].accounts[sAccIdx].balance -= amount;
            users[receiverIdx].accounts[rAccIdx].balance += amount;

            int senderPos = users[currentUserIndex].transactionCount;
            if (senderPos < 10) {
                users[currentUserIndex].transactions[senderPos].from = users[currentUserIndex].username;
                users[currentUserIndex].transactions[senderPos].to = users[receiverIdx].username;
                users[currentUserIndex].transactions[senderPos].amount = amount;
                users[currentUserIndex].transactionCount++;
            }

            int receiverPos = users[receiverIdx].transactionCount;
            if (receiverPos < 10) {
                users[receiverIdx].transactions[receiverPos].from = users[currentUserIndex].username;
                users[receiverIdx].transactions[receiverPos].to = users[receiverIdx].username;
                users[receiverIdx].transactions[receiverPos].amount = amount;
                users[receiverIdx].transactionCount++;
            }

            cout << "\n>>> Transfer Successful! <<<" << endl;
            return;
        }
        else {
            cout << "Error: Insufficient balance in your selected account. Try a different account or amount." << endl;
        }
    }
}