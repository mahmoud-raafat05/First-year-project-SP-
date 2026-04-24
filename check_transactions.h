#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"
using namespace std;

void checkTransactions(User users[], int userIdx) {
    cout << endl << "Transactions for " << users[userIdx].username << ":" << endl;
    bool hasTransactions = false;
    double sentTotal = 0;
    double receivedTotal = 0;

    for (int i = 0; i < 10; i++) {
        if (users[userIdx].transactions[i].from != "" && users[userIdx].transactions[i].to != "") {
            hasTransactions = true;
            cout << "From: " << users[userIdx].transactions[i].from
                 << " | To: " << users[userIdx].transactions[i].to
                 << " | Amount: " << users[userIdx].transactions[i].amount << endl;

            if (users[userIdx].transactions[i].from == users[userIdx].username) {
                sentTotal += users[userIdx].transactions[i].amount;
            }
            if (users[userIdx].transactions[i].to == users[userIdx].username) {
                receivedTotal += users[userIdx].transactions[i].amount;
            }
        }
    }

    if (!hasTransactions) {
        cout << "No transactions found." << endl;
    } else {
        cout << "Total Sent: " << sentTotal
             << " | Total Received: " << receivedTotal << endl;
    }
}
