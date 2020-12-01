//Header file for the savings account
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

class SavingAccount : Account
{
private:
	//placeholder
public:
	SavingAccount(){}	//default constructor
	SavingAccount(int accountNumber, double balance, double interestRate);	//what is passed in from the account.h file
};
#endif

/* SAVINGS ACCOUNT RULES
	No monthly fees and interest rate set by bank officials that can be modified
	Must have:
		account holder's name, phone number, and address
		interest rate
		total $ available
		records of all transactions with dates
		a unique account number
*/