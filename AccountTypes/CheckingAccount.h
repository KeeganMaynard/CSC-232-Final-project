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
	string deposit(double amount);
	string withdraw(double amount);
	void closeAccount();
};

string CheckingAccount::deposit(double amount)
{
	if (isOpen())
	{
		try
		{
			if (amount < .01)
			{
				throw "Invalid operation. You cannot deposite a negative or zero amount" << endl;
			}
			else
			{
				//setbalance(getbalance() + amount);
			}

			string statement = "$" << amount << " has been depositited into your checking account" << endl;
			return statement;
		}
		catch (string err)
		{
			return err;
		}
	}
	else
	{
		return "The account is closed at this time\n";
	}
}

string CheckingAccount::withdraw(double amount)
{
	if (isOpen())
	{
		try
		{
			if (amount < 0.01)
			{
				throw "Invalid operation. You cannot withdraw a negative or zero amount";
			}
		}
		catch (string err)
		{
			return err;
		}

		double newBalance = getBalance() - amount;

		if (newBalance < 0.0)
		{
			string statement = "Account has insufficient funds to withdraw $" << amount << endl;
			return statement;
		}
		else
		{
			setBalance(newBalance);
		}
		string statement = "$" << amount << " has been withdrawn from your account" << endl;
		return statement;
	}
	else
	{
		return "The account is closed at this time\n";
	}
}

void CheckingAccount::closeAccount()
{
	setIsClosed(true);
}
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