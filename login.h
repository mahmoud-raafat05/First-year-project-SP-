#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "all_structures.h"

void login(User users[], int size = 10)
{
	string username, password;
	
	bool found = false; // to check if user is found
	
	for (int j = 0; j < 3; j++)
	{
		cin.ignore();
		cout << "please enter your username: ";
		getline(cin, username); // to read the username with spaces
		cout << "please enter your password: ";
	
		cin >> password;

		for (int i = 0; i < size; i++)
		{

			if ((users[i].username == username) && (users[i].password == password))
			{
				found = true;
				cout << "Login successful! Welcome, " << users[i].username << "." << endl;
				break;
			}
		}
		if (found)
			break; // ← stop outer loop if login succeeded

		if (j < 2) // ← don't show "try again" on the last attempt
			cout << "Invalid! You have " << (2 - j) << " attempt(s) left." << endl;
		else
			cout << "Too many failed attempts. Session terminated." << endl;
	}
}
