//Header file for organization and abstraction of function calls 
#ifndef OS_H
#define OS_H
#include <iostream>
#include <string>
#include "BankOfficials.h"
#include "SystemAdmin.h"
#include "UserAccounts.h"
using namespace std;

string accountAge()
{
	string input;
	cout << "Choose your account type:\n [1] Existing Account\n [2] Create Account" << endl;
	getline(cin, input);
	return input;
}
#endif