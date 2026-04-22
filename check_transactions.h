#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "all_structures.h"

void checkTransactions(User u) {
    cout << endl << "Transactions for " << u.username << ":" << endl;
    bool hasTransactions = false;
    double sentTotal = 0;
    double receivedTotal = 0;
    for (int i = 0; i < 10; i++) {
        if (u.transactions[i].from != "" && u.transactions[i].to != "") //check if the slot is filled 
        {
            hasTransactions = true;
            cout << "From: " << u.transactions[i].from
                 << " | To: " << u.transactions[i].to
                 << " | Amount: " << u.transactions[i].amount << endl; // print one transaction line
            if (u.transactions[i].from == u.username) {
                sentTotal += u.transactions[i].amount;
            }
            if (u.transactions[i].to == u.username) {
                receivedTotal += u.transactions[i].amount;
            }
        }
    }
    if (!hasTransactions) {
        cout << "No transactions found." << endl; // if no transactions, show message
    } 
    else {
        cout << "Total Sent: " << sentTotal
             << " | Total Received: " << receivedTotal << endl;
    }
}