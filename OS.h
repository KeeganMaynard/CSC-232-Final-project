//Header file for organization and abstraction of function calls 
#ifndef OS_H
#define OS_H
#include <iostream>
#include <string>
#include "UserTypes/BankOfficials.h"
#include "UserTypes/SystemAdmin.h"
#include "UserTypes/UserAccounts.h"
using namespace std;

string accountAge()
{
	string input;
	cout << "Choose your account type:\n [1] Existing Account\n [2] Create Account\n [3] Exit" << endl;
	getline(cin, input);
	return input;
}

int accountType()
{
	string option;
	int type;
	cout << "Login to your account type:\n [1] System Administrator\n [2] Bank Official\n [3] Bank Member\n [4] Cancel" << endl;
	getline(cin, option);
	try
	{
		if (option.length() == 1)
		{
			type = stoi(option);
		}
		else
		{
			throw 1;
		}
	}
	catch (...)
	{
		return -1;
	}

	return type;
}

int newAccountType()
{
	string option;
	int newType;
	cout << "Choose desired type of account:\n [1] System Administrator Account\n [2] Bank Official Account\n [3] Bank Member Account" << endl;
	getline(cin, option);
	try
	{
		if (option.length() == 1)
		{
			newType = stoi(option);
		}
		else
		{
			throw 1;
		}
	}
	catch (...)
	{
		return -1;
	}

	return newType;
}
#endif
