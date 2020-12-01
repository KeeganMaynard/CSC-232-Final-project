//Header file for the checking accounts
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

class CheckingAccount : public Account
{
private:
	//placeholder for what needs to go here later
public:
	CheckingAccount () {}	//default constructor
	CheckingAccount(int accountNumber, double balance, double interestRate);	//what is passed in from the account.h file
};
#endif

/* CHECKING ACCOUNT RULES
	No monthly fees and no interest
	Must have:
		account holder's name, phone number, and address
		interest rate
		total $ available
		records of all transactions with dates
		a unique account number 
*/