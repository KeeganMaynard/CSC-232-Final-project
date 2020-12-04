//Header file for the savings account
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <string>
#include <iostream>
#include "Account.h"
using namespace std;

class SavingAccount : public Account
{
private:
	//placeholder
public:
	SavingAccount(){}	//default constructor
	SavingAccount(int accountNumber, double balance, double interestRate);	//what is passed in from the account.h file
	string deposit(double amount);
	string withdraw(double amount);
	void closeAccount();

};

string SavingAccount::deposit(double amount)
{
	if (isOpen())
	{
		try
		{
			if (amount < 0.01)
			{
				throw "Invalid input. You cannot deposite a negative or zero amount\n";
			}
			else
			{
				setBalance(getBalance() + amount);
			}
			string statement = "$" << amount << " has been deposited into your account" << endl;
			return statment;
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

string SavingAccount::withdraw(double amount)
{
	if (isOpen())
	{
		if (amount < 0.01)
		{
			return "Invalid input. You cannot withdraw a negative or zero amount\n";
		}
		else
		{
			double newBalance = getBalance() - amount;

			if (newBalance < 0.0)
			{
				return "The account has insufficient funds for this withdraw\n";
			}
			else
			{
				setBalance(newBalance);
			}
			string statement = "$" << amount << " has been withdrawn from your account" << endl;
			return statement;
		}
	}
	else
	{
		return "This account is closed at this time\n";
	}
}

void SavingAccount::closeAccount()
{
	setIsClosed(true);
}
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