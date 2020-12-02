#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Account{
private:
    string username, password;
    string firstName, lastName;
    string phoneNumber, address;
    string openingDate, closingDate, maturityDate;
    double balance, interestRate, insufficientCharge;
    int accountNumber, fees;
    bool isClosed;
public:
    Account() {}        //default constructor
    Account(int accountNumber, double balance, double interestRate);
    virtual string deposit(double amount) = 0;
    virtual string withdraw(double amount) = 0;
    void calcInterest();
    void applynsfCharge();
    virtual void closeAccount() = 0;

    //setter and getter functions 
    void setAccountNum(int num);
    int getAccountNum();
    void setBalance(double bal);
    double getBalance();
    void setInterest(double rate);
    double getInterest();
    void setIsClosed(bool YN);
    bool isOpen();

    static double roundBal(double value, int decimal);
    static int currentAccount;
    static string displayBal(double value);
    static void incrementAccountNum(int lastAccount);
};

int Account::currentAccount = 1;

//constructor
Account::Account(int accountNumber, double balance, double interestRate)
{
    setAccountNum(accountNumber);
    setBalance(balance);
    setInterest(interestRate);
    setIsClosed(false);
}

double Account::roundBal(double value, int decimal)
{
    double factor = pow(10, decimal);
    value = value * factor;

    int temp = value;
    int hightemp = temp + 1;

    double first = abs(value - temp);
    double second = abs(value - hightemp);

    temp = (first < second) ? temp : hightemp;
    value = temp / factor;

    return value;
}

void Account::calcInterest()
{
    if ((balance > 0) && (isOpen))
    {
        double dailyRate = interestRate / 365;
        double dailyInterest = dailyRate * balance;
        balance = roundBal(balance + dailyInterest, 2);
    }
}

//Setter and getter function definitions
void Account::setAccountNum(int num)
{
    accountNumber = num;
}

int Account::getAccountNum()
{
    return accountNumber;
}

void Account::setBalance(double bal)
{
    balance = roundBal(bal, 2);
}

double Account::getBalance()
{
    return balance;
}

void Account::setInterest(double rate)
{
    try
    {
        if ((rate > 10.00) || (rate < 0.10))
        {
            throw 1;
        }
        else
        {
            interestRate = rate;
        }
    }
    catch (int a)
    {
        cout << "Invalid interest rate entered. Please try again\n";
        abort();
    }
}

void Account::getInterest()
{
    return interestRate;
}

bool Account::setIsClosed(bool YN)
{
    isClosed = (YN == true) ? true : false;
}

bool Account::isOpen()
{
    return !isClosed;
}

string Account::displayBal(double value)
{
    string number = to_string(value);
    return number.substr(0, number.length() - 4);
}

void Account::incremementAccountNum(int lastAccount)
{
    //fill this function to increment the account numbers as users are added 
}
#endif