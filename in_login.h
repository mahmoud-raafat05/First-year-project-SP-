#pragma once
#include <iostream>
#include <string>
#include "all_structures.h"
// #include "check_balance.h"
#include "check_transactions.h"
#include "add_new_account.h"
#include "transfer.h"
using namespace std;

void main_menu(User users[], int userIdx)
{

    while (true)
    {
        cout << "\n \n-----welcome to the Main Menu----- \n";
        cout << "1-Check balance \n";
        cout << "2-Check transactions \n";
        cout << "3-Add new account \n";
        cout << "4-Transfer money \n";
        cout << "5-Exit \n";

        int main_choice;
        cin >> main_choice;

        if (main_choice == 5)
        {
<<<<<<< Updated upstream
            // checkBalance(users,userIdx);
=======
            cout << "------Thanks for using our app------ /n";
            break;
        }

        switch (main_choice)
        {
        case 1:
        {
            checkbalance(users, userIdx);
>>>>>>> Stashed changes
            break;
        }
        case 2:
        {
            checkTransactions(users, userIdx);
            break;
        }
        case 3:
        {
            AddNewAccount(users, userIdx);
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

        char cont;
        cout << "\n Do you want to continue? (y/n) \n";
        cin >> cont;
        if (cont == 'n')
        {
            cout << "------Thanks for using our app------ /n";
            break;
        }
    }
}