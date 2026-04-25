
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "all_structures.h"

int login(User users[]) //int mkan void
{
	string username, password;
	bool found = false; // to check if user is found
	int counter = 0;

	while (counter < 3 && !found)
	{

		cout << "please enter your username: " << endl;
		cin.ignore();
		getline(cin, username);

		cout << "please enter your password: " << endl;

		cin >> password; // gitline bt3mel errors kteer

		for (int i = 0; i < 10; i++)
		{

			if (users[i].username == username && users[i].password == password)
			{
				found = true;
				cout << "----- Login successful! Welcome, " << users[i].username << ". ------" << endl;

				return i;
			}
		}
		if (!found)
		{
			counter++;

			if (counter < 3)
			{
				cout << "Invalid username or password. Please try again." << endl;
			}
		}
	}
	if (!found)
	{
		cout << "You have reached the maximum number of attempts." << endl;
	}
	return -1;
}