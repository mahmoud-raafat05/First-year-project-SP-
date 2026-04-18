#include <iostream>
#include <string>
#include "all_structures.h"
#include "login.h"
#include "transfer.h"
#include <fstream>
using namespace std;

User users[10] = {
    {
        1, "hana", "hana_123", "hana@gmail.com", "new cairo", "01111567894", // user's info
        {{"12223", "hana morsy", "455", "03/27", "CIB", 8008.5}},            // account info
        {{"hana", "mahmoud", 500}}                                           // transactions
    },
    {
        2, "mahmoud", "mahmoud@pass", "mahmoud@gmail.com", "new nozha", "01114563879", // user's info
        {{"12224", "mahmoud medhat", "320", "07/26", "bank masr", 405060.33}},         // account info
        {{"mahmoud", "hana", 10000}}                                                   // transactions
    } 
}; 


     int main()
    {
        int choices;
        cout << "                              Welcome to our program            " << endl;
        cout << "                         ----------------------------------      " << endl;
        cout << "please choose from the following options: " << endl;
        cout << "1- login" << endl;
        cout << "2- signup" << endl;
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            int userIdx = login(users);
            if (userIdx != -1)
            {
                transfer(userIdx);
            }
            break;
        }
        }
        return 0;
    }