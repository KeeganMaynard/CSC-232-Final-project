#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include "Account.h"
#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

/*
Users need to be able to see all transactions made within 86,400 seconds(24 hours)
They can have a vector(?) containing all of their accounts (Maybe have an option to print and then view each one?)
Set previousLogin everytime they log out?
*/

class UserAccount: protected Account{
    private:
        int currentLogin, previousLogin;

        string convertTime(int seconds){
            time_t rtime = (seconds);
            struct tm * tempTime;
            tempTime = localtime(&rtime);
            return asctime(tempTime);
        }

    public:
        UserAccount(){
        }

        UserAccount(string user, string pass, string fName, string lName, string phone, string add, string opening, string closing, string maturity, double bal, double interest, int accountNum){
            username = user;
            password = pass;
            firstName = fName;
            lastName = lName;
            phoneNumber = phone;
            address = add;
            openingDate = opening;
            closingDate = closing;
            maturityDate = maturity;
            balance = bal;
            interestRate = interest;
            accountNumber = accountNum;
        }

        void changePassword(){ //Password change function
            string tempPassword;
            
            cout << "Please enter your current password" << endl;
            getline(cin, tempPassword);
            
            //If password matches then continue
            if (tempPassword == password){
                cout << "What would you like to change your password to? " << endl;
                getline(cin, tempPassword);
                password = tempPassword;
                cout << "Your password has been succesfully changed!" << endl;
                return;
            }
            
            //Else deny
            else{
                cout << "Incorrect password." << endl;
                return;
            }
        }

        void login(){
            string tempUser, tempPass;
            
            cout << "Please enter your username" << endl;
            getline(cin, tempUser);

            cout << "Please enter your password" << endl;
            getline(cin, tempPass);
            
            if((tempUser == username) && (tempPass == password)){
                time_t t = time(0);
                currentLogin = t;
                string currentTime = convertTime(t);
                cout << "Welcome " << firstName << " to BEAR Bank! Your home for all your banking needs!" << endl << "It is currently: " << currentTime << endl; 
                //Login code here
            }
            
            else{
                cout << "Incorrect Username or Password." << endl;
                return;
            }
        }
};

#endif