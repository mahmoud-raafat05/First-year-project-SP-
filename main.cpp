#include <iostream>
#include <string>
#include "all_structures.h"
#include "login.h"
#include "transfer.h"
#include "in_login.h"
#include "sign_up.h"
#include "check_balance.h"
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

int userIdx;
int usercount = 2;

int main()
{
   while(true){
    srand(time(0));
    int choices;
    userIdx = -1;
    cout << "                              Welcome to our program            " << endl;
    cout << "                         ----------------------------------      " << endl;
    cout << "please choose from the following options:(1 or 2) " << endl;
    cout << "1- login\n";
    cout << "2- signup\n";
    cout << "3- exit\n";
    cout << "your choice:";
    cin >> choices;

    if (choices == 1)
    {
        userIdx = login(users);
    }
    else if (choices == 2)
    {
        if (signup(users, usercount) != -1)
        {
            userIdx = usercount - 1;
        }
    }
    else if (choices == 3)
    {
        cout << "------Thanks for using our app------";
        return 0;
    }
    else
    {
        cout << "invalid option\n";
    }

    // --------------------------------------------
    if (userIdx != -1)
    {
        main_menu(users, userIdx);
    }
    // --------------------------------------------
}
    return 0;
}
