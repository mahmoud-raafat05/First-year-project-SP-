#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "all_structures.h"
//صلي على النبي
void checkTransactions(user &u) {
    cout << "\n--- Transactions for " << u.username << " ---\n";
    bool found = false;          // to check if any transactions exist
    double totalSent = 0;        // total money sent by this user
    double totalReceived = 0;    // total money received by this user
    // Loop through the 10 possible transaction slots
    for (int i = 0; i < 10; i++) {
        // Only print if the transaction slot is used (not empty)
        if (!u.transactions[i].from.empty() && !u.transactions[i].to.empty()) {
            found = true;
            // Print transaction details
            cout << "From: " << u.transactions[i].from
                 << " | To: " << u.transactions[i].to
                 << " | Amount: " << u.transactions[i].amount << endl;
            // Update totals depending on whether the user is sender or receiver
            if (u.transactions[i].from == u.username)
                totalSent += u.transactions[i].amount;
            if (u.transactions[i].to == u.username)
                totalReceived += u.transactions[i].amount;
        }
    }
    // If no transactions were found, tell the user 
    if (!found) {
        cout << "No transactions recorded.\n";
    } else {
        // Print summary totals
        cout << "-----------------------------------\n";
        cout << "Summary: Sent = " << totalSent
             << " | Received = " << totalReceived << endl;
    }
}
