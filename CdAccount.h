//header file for the cd accounts
#ifndef CDACCOUNT_H
#define CDACCOUNT_H
#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

class CdAccount : Account
{
private:
	//placeholder
public:
	CdAccount(){}	//default constructor
	CdAccount(int accountNumber, double balance, double interestRate)	//need to include the length of the term somehow
};
#endif

/* CD ACCOUNT RULES
	fixed term and fixed interest
	early cancellation will result in a penalty fee based on the number of days remaining, no interest will be paid
	Must have:
		account holder's name, phone number, and address
		interest rate
		total $ available
		records of all transactions with dates
		a unique account number
*/