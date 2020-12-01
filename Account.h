#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account{
protected:
    string username, password;
    string firstName, lastName;
    string phoneNumber, address;
    string openingDate, closingDate, maturityDate;
    double balance, interestRate;
    int accountNumber, fees;
public:
    Account() {}        //default constructor
};

#endif