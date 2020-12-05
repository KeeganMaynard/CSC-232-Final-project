//.cpp file to implement the Account.h header file
#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

void createAccount();
void exitAccount();

void createAccount()
{
	//create default accounts to initialize the bank -- prove it works
}

void exitAccount()
{
	Account::nextAccountID();
}

double AccountVersion::nsfCharge;

//Constructor
AccountVersion::AccountVersion(string accountType, double mFee, double sFee, double intRate, double min)
{
	if (accountType == "default")
	{
		monthFee = 0.0;
		serviceFee = 0.0;
		rate = 0.0;
		minBalance = 0.0;
		accountType = "";
	}
	else
	{
		//read from a file to build account information
		ifstream inFile;
		inFile.open(file);	//determine which file needs to be opened
		
		if (inFile)
		{
			//split the text into substrings to fill in the variables
			inFile.close();
		}
		else
		{
			//used to create a new account type
			inFile.close();
			monthFee = mFee;
			serviceFee = sFee;
			rate = intRate;
			minBalance = min;
			accountType = accountType;
			//save this information to a file
		}
	}
}

//setters and getters
void AccountVersion::setMonthFee(double amount)
{
	monthFee = amount;
}

double AccountVersion::getMonthFee()
{
	return monthFee;
}

void AccountVersion::setServiceFee(double amount)
{
	serviceFee = amount;
}

double AccountVersion::getServiceFee()
{
	return serviceFee;
}

void AccountVersion::setNsfCharge(double amount)
{
	nsfCharge = amount;
}

double AccountVersion::getNsfCharge()
{
	return nsfCharge;
}

bool AccountVersion::setInterest(double intRate)
{
	if (intRate > 0 && intRate < 8)
	{
		rate = intRate;
		return true;
	}
	else
	{
		return false;
	}
}

double AccountVersion::getInterest()
{
	return rate;
}

void AccountVersion::setMinimum(double amount)
{
	minBalance = round(amount, 2);
}

double AccountVersion::getMinimum()
{
	return minBalance;
}

void AccountVersion::setType(string type)
{
	accountType = type;
}

string AccountVersion::getType()
{
	return accountType;
}

string AccountVersion::getAmount(double amount)
{
	string value = to_string(input);
	//might need to create a substring to trim off extra characters
}

double AccountVersion::round(double amount, int rounded)
{
	double factor = pow(10, rounded);
	amount = amount * factor;

	int roundNum = amount;		//type conversion cuts off decimals 
	int roundUp = roundNum + 1;	//incase the number rounds up instead of down

	double lowNum = abs(amount - roundNum);
	double highNum = abs(amount - roundUp);

	roundNum = (lowNum < highNum) ? roundNum : roundUp;
	amount = roundNum / factor;	//divide to calculate the final decimal

	return amount;
}

//Implementation of Account Class
string Account::routeID = "";		//will need to be assigned a value
string Account::nextChecking;
string Account::nextSaving;
string Account::nextCD;
string Account::nextAccount;

//constructor for new accounts
Account::Account(string accountType, string ID, string firstName, string lastName, string phone, string address, time_t today, double amount) : AccountVersion(accountType)
{
	//set the account number
	//set account holder information
	//set up time variables
	//set the status of the account
	//set the balance
	//set last interest caculation
}

//constructor for existing accounts
Account::Account(string accountID) : AccountVersion("default")
{
	buildFromInfo(accountID);
	calcInterest();
}

//Account setters and getters
void Account::setAccountID(string accountNum)
{
	accountID = accountNum;
}

string Account::getAccountID()
{
	return accountID;
}

void Account::setHolderID(string holderID)
{
	accountHolderID = holderID;
}

string Account::getHolderID()
{
	return accountHolderID;
}

void Account::setHolderFirst(string holderFirst)
{
	accountHolderFirst = holderFirst;
}

string Account::getHolderFirst()
{
	return accountHolderFirst;
}

void Account::setHolderLast(string holderLast)
{
	accountHolderLast = holderLast;
}

string Account::accountHolderLast()
{
	return accountHolderLast;
}

void Account::setHolderPhone(string holderPhone)
{
	accountHolderPhone = holderPhone;
}

string Account::getHolderPhone()
{
	return accountHolderPhone;
}

void Account::setHolderAddress(string holderAddress)
{
	accountHolderAddress = holderAddress;
}

string Account::getHolderAddress()
{
	return accountHolderAddress;
}

string Account::getHolderInfo()
{
	return accountHolderFirst + " " + accountHolderLast + " " + accountHolderPhone + " " + accountHolderAddress;
}

string Account::getAccountInfo()
{
	//return the status of the account and information such as type of account, balance, and personal info
}

void Account::setClosedAccount(string official)
{
	accountClosed = official;
}

time_t Account::getOpenDay()
{
	return dayOpen;
}

void Account::setCloseDay(time_t day)
{
	dayClose = day;
}

string Account::getCloseDay()
{
	return convert(dayClose);
}

time_t Account::getMaturityDay()
{
	return dayMature;
}

time_t Account::getTerm()
{
	return dayMature - dayOpen;
}

void Account::setBalance(double amount)
{
	balance = amount;
}

double Account::getBalance()
{
	return balance;
}

void Account::setRestricted(bool condition)
{
	restricted = condition;
}

void Account::setUnrestrictued(bool condition)
{
	active = condition;
}

bool Account::getRestricted()
{
	return restricted;
}

bool Account::getUnrestricted()
{
	reutrn active;
}

string Account::deposit(double amount)
{
	balance += round(amount, 2);
	saveInfo("Deposit", amount);
	return "Successful deposit complete.";
}

string Account::withdraw(double amouont)
{
	time_t now;
	time(&now);		//check this one

	//implement the code to determine if the withdraw is allowed/possible 
	//implement the code to save the information
}

void Account::accountHistory(string opened, string closed)
{
	//implement the code to dispay the information from the text file containing the account and its info
}

time_t Account::historyAssist(string date)
{
	//implement the code to convert the strings from the text file to integers
}

string Account::saveInfo()
{
	//implement the code to update the text files after changes have been made
}

void Account::buildFromInfo(string accountID)
{
	//implement the code to build an account from a text file 
}

void Account::nextAccountID()
{
	//implement the code to store the next account number in a file for later access
}

string Account::convert(time_t time)
{
	string date = ctime(&time);		//check this one
	return date;
}

string Account::incrementAccount(string lastAccount)
{
	//implement code to increment the account numbers
}

void Account::transaction(string account, double amount)
{
	//implement code to add the transaction to the appropriate file with information
}

void Account::calcInterest()
{
	//implement code to calculate the interst
	//will need the number of days from the last time function was called
}