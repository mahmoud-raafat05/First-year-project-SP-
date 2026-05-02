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

    cout << "\n--- Transfer Money ---" << endl;
    cout << "Enter Receiver Phone: ";
    cin >> targetPhone;

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

    if (users[currentUserIndex].accounts[0].balance >= amount) {
        users[currentUserIndex].accounts[0].balance -= amount;
        users[receiverIdx].accounts[0].balance += amount;

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
            users[receiverPos].transactions[receiverPos].amount = amount;
            users[receiverIdx].transactionCount++;
        }

        cout << "Transfer Successful!" << endl;
    }
    else {
        cout << "Error: Insufficient balance." << endl;
    }
}