#include <iostream>
#include <string>
#include "all_structures.h"
#include "sign_up.h"
#include "login.h"
<<<<<<< Updated upstream
=======
#include "check_transactions.h"
#include "add_new_account.h"
#include "transfer.h"
#include "in_login.h"
>>>>>>> Stashed changes
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
    }};

<<<<<<< Updated upstream
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
        login(users);
        break;
    }
=======
int usercount = 2;
int userIdx;

int main()
{
    int main_choices;
    int login_choice;
    cout << "                              Welcome to our program            " << endl;
    cout << "                         ----------------------------------      " << endl;
    cout << "please choose from the following options: " << endl;
    cout << "1- login" << endl;
    cout << "2- signup" << endl;
    while (true)
    {

        cin >> main_choices;

        switch (main_choices)
        {
        case 1:
        {
            userIdx = login(users);
            in_login();
            cin >> login_choice;
            switch (login_choice)
            {
            case 1:
            {
                // check_balance(users,userIdx)
                break;
            }
            case 2:
            {
                // checkTransactions(users,userIdx);
                break;
            }
            case 3:
            {
                // AddNewAccount(users,usercount,userIdx)
                break;
            }
            case 4:
            {
                if (userIdx != -1)
                {
                    transfer(userIdx);
                }
                break;
            }
            }
            break;
        }
        case 2:
        {
            signup(users, usercount);
            userIdx = usercount;
            in_login();
            cin >> login_choice;
            switch (login_choice)
            {
            case 1:
            {
                // check_balance(users,userIdx)
                break;
            }
            case 2:
            {
                // checkTransactions(users,userIdx);
                break;
            }
            case 3:
            {
                // AddNewAccount(users,usercount,userIdx)
                break;
            }
            case 4:
            {
                if (userIdx != -1)
                {
                    transfer(userIdx);
                }
                break;
            }
            }
            break;
        }
        }
    }

>>>>>>> Stashed changes
    return 0;
}