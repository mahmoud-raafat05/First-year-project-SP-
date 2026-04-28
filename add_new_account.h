#pragma once
#include <string>
#include <cstdlib> 
#include "all_structures.h"
#include <iostream>

using namespace std;


void AddNewAccount(User users[], int usercount) {
    int id;
    cout << "Enter your id :" << endl;
    cin >> id;

   
        if (users[usercount].id == id) {
            for (int j = 0; j < 3; j++) {
                if (users[usercount].accounts[j].card_number.empty()) {
                    
                    cout << "Enter Card Number :" << endl;
                    cin >> users[usercount].accounts[j].card_number;

                    cin.ignore();
                    cout << "Enter Holder Name :\n";
                    getline(cin, users[usercount].accounts[j].holder_name);

                    cout << "Enter Cvv_code :\n";
                    cin >> users[usercount].accounts[j].cvv_code;

                    cout << "Enter Expiration Date :\n";
                    cin >> users[usercount].accounts[j].expiration_date;

                    cin.ignore();
                    cout << "Enter Bank Name :\n";
                    getline(cin, users[usercount].accounts[j].bank_name);

                    users[usercount].accounts[j].balance = 1000.0 + rand() % 3000;

                    cout << "Account added successfully\n";
                    return; 
                }
            
            
            }
            cout << "Sorry, you already have the maximum limit of 3 accounts\n";
            return;
    }
    
    cout << "Error: User ID not found!\n";
}