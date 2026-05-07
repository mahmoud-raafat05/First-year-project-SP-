#pragma once
#include <string>
#include <cstdlib> 
#include <iostream>
#include <cctype>
#include <ctime>

#include "all_structures.h"

using namespace std;

bool isDigitsOnly(string str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void AddNewAccount(User users[], int usercount) {
    int id;
    cout << "Enter your id :" << endl;
    cin >> id;

    if (users[usercount].id == id) {

        bool added = false;

        for (int j = 0; j < 3; j++) {

            if (users[usercount].accounts[j].card_number.empty()) {

                string card, cvv;


                cout << "Enter Card Number (16 digits):\n";
                cin >> card;

                while (card.length() != 16 || !isDigitsOnly(card)) {
                    cout << "Invalid card number! Try again:\n";
                    cin >> card;
                }

                users[usercount].accounts[j].card_number = card;

                cin.ignore();
                cout << "Enter Holder Name:\n";
                getline(cin, users[usercount].accounts[j].holder_name);


                cout << "Enter CVV (3 digits):\n";
                cin >> cvv;

                while (cvv.length() != 3 || !isDigitsOnly(cvv)) {
                    cout << "Invalid CVV! Try again:\n";
                    cin >> cvv;
                }

                users[usercount].accounts[j].cvv_code = cvv;

                cout << "Enter Expiration Date:\n";
                cin >> users[usercount].accounts[j].expiration_date;

                cin.ignore();
                cout << "Enter Bank Name:\n";
                getline(cin, users[usercount].accounts[j].bank_name);

                users[usercount].accounts[j].balance = 1000 + rand() % 3000;

                cout << "Account added successfully\n";

                added = true;
                break;
            }
        }

        if (!added) {
            cout << "Sorry, you already have the maximum limit of 3 accounts\n";
        }
    }
    else {
        cout << "Error: User ID not found!\n";
    }
}