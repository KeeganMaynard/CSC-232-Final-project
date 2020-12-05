#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class AccountVersion{
private:
    string accountType;
    double monthFee;    //monthly fee
    double serviceFee;  //service fee
    double nsfCharge;   //penalty for insufficient funds
    double rate;        //insurace rate
    double minBalance;  
public:
    AccountVersion() {}        //default constructor
    AccountVersion(string accountType, double mFee = 0.0, double sFee = 0.0, double intRate = 0.0, double min = 0.0);
    void setMonthFee(double amount);
    double getMonthFee();
    void setServiceFee(double amount);
    double getServiceFee();
    void setNsfCharge(double amount);
    double getNsfCharge();
    bool setInterest(double intRate);
    double getInterest();
    void setMinimum(double amount);
    double getMinimum();
    void setType(string type);
    string getType();
    string gitAmount(double amount);
    double round(double amount, int rounded);
};

class Account : public AccountVersion
{
private:
    string routeID;                     //variable to track the routing number
    string accountID;                   //variable to track the account number
    string accountHolderID;             //variable to track the user ID
    string accountHolderFirst;          //variable to track the account holder's first name
    string accountHolderLast;           //variable to track the account holder's last name
    string accountHolderPhone;          //variable to track the account holder's phone number
    string accountHolderAddress;        //variable to track the account holder's address
    string accountClosed;               //variable to track who closed the account
    double balance;                     //variable to track the balance of the account
    time_t dayOpen;                     //variable to mark the day the account was opened
    time_t dayClose;                    //variable to mark the day the account is closed
    time_t dayMature;                   //variable to mark the day the account is mature
    time_t lastInterest;                //variable to mark the last time interest was calculated
    bool restricted;                    //variable to track if the account is restricted
    bool active;                        //variable to track if the account is not restricted

    string nextChecking;                //variable to mark the next checking account number
    string nextSaving;                  //variable to mark the next saving account number
    string nextCD;                      //variable to mark the next CD account number
    string nextAccount;                 //variable to mark the next unused account number

    void setBalance(double amount);
    string convert(time_t time);        //function to convert the time to a string
    string incrementAccount(string lastAccount);    
    void transaction(string account, double amount); 
    void calcInterest();

    friend void createAccount();        //might need to change

public:
    Account(string accountType = "", string ID = "", string firstName = "", string lastName = "", string phone = "", string address = "", time_t today = 0, double amount = 0.0);
    Account(string accountID);
    void setAccountID(string accountNum);
    string getAccountID();
    void setHolderID(string holderNum);
    string getHolderID();
    void setHolderFirst(string holderFirst);
    string getHolderFirst();
    void setHolderLast(string holderLast);
    string getHolderLast();
    string getHolderFull();
    void setHolderPhone(string phoneNum);
    string getHolderPhone();
    void setHolderAddress(string address);
    string getHolderAddress();
    string getHolderInfo();
    string getAccountInfo();
    void setClosedAccount(string official);
    time_t getOpenDay();
    void setCloseDay(time_t day);
    string getCloseDay();
    time_t getMaturityDay();
    time_t getTerm();
    double getBalance();
    void setRestricted(bool condition);
    void setUnrestrictued(bool condition);
    bool getRestricted();
    bool getUnrestricted();
    string deposit(double amount);
    string withdraw(double amount);
    void accountHistory(string openDay, string closeDay);
    time_t historyAssist(string date);
    string saveInfo();
    void buildFromInfo(string accountID);
    void nextAccountID();

};

#endif