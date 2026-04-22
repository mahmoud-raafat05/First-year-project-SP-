#pragma once
<<<<<<< Updated upstream
=======
#include <iostream>
#include <string>
#include "all_structures.h"

using namespace std;

extern User users[10];

void transfer(int currentUserIndex)
{
    if (currentUserIndex == -1)
        return;

    string targetPhone;
    double amount;

    cout << "\n--- Transfer Money ---" << endl;
    cout << "Enter Receiver Phone: ";
    cin >> targetPhone;

    int receiverIdx = -1;
    for (int i = 0; i < 10; i++)
    {
        if (users[i].phone == targetPhone)
        {
            receiverIdx = i;
            break;
        }
    }

    if (receiverIdx == -1)
    {
        cout << "User not found!" << endl;
        return;
    }

    cout << "Enter amount: ";
    cin >> amount;

    if (users[currentUserIndex].accounts[0].balance >= amount)
    {
        users[currentUserIndex].accounts[0].balance -= amount;
        users[receiverIdx].accounts[0].balance += amount;

        cout << "Transfer Successful!" << endl;

        users[currentUserIndex].transactions[0].from = users[currentUserIndex].username;
        users[currentUserIndex].transactions[0].to = users[receiverIdx].username;
        users[currentUserIndex].transactions[0].amount = amount;
    }
    else
    {
        cout << "Error: Insufficient balance." << endl;
    }
}
>>>>>>> Stashed changes
