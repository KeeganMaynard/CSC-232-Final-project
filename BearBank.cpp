//The main .cpp file for the project

#include "BankOfficials.h"
#include "OS.h"
#include <iostream>
#include <string>
using namespace std;

string encrypt(string);
string decrypt(string);

int main()
{
	bool run = true;
	string userInput, exit;
	BankOfficials<string> employeeList;

	while (run)
	{
		userInput = accountAge();

		if (userInput == "1")
		{
			int type = accountType();
			
			switch (type) {

			case 1://System Admin
			{
				cout << "Enter System administrator login ID and password: " << endl;
				break;
			}

			case 2://Bank Official
			{
				cout << "Enter Bank official login ID and password: " << endl;
				break;
			}

			case 3://Bank Member
			{
				cout << "Enter Bank member login ID and password: " << endl;
				break;
			}

			case 4://Exit
			{
				break;
			}

			default:
			{
				cout << "Invalid input. Please try again" << endl;
				break;
			}
			}
		}
		else if (userInput == "2")
		{
			int newType = newAccountType();

			switch (newType)
			{
			case 1://new bank official account
			{
				cout << "Enter the require System administrator login information:";
				break;
			}
			case 2://new bank member account
			{
				cout << "Enter the required Bank official login information:";
				break;
			}
			default:
			{
				cout << "Invalid input. Please try again" << endl;
				break;
			}
			}
		}
		else if (userInput == "3")
		{
			cout << "Goodbye!" << endl;
			run = false;
		}
		else
		{
			cout << "Invalid input" << endl;
			continue;
		}
	}
}

string encrypt(string s){ //Basic string encryption
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i]+45;
    }
    return s;
}

string decrypt(string s){ //Decryption key for strings
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i]-45;
    }
    return s;
}

//						PROJECT INFO

/* SYSTEM ADMIN
	if the user logs into a system admin account they will need to be able to:
		create, enable/disable, delete, and modify bank official accounts
		create, delete, and modify member bank accounts
		retrieve user login ID and change the password
*/

/* BANK OFFICIALS
	if the user logs into a bank employee account they will need to be able to:
		open or close an account (with the information still saved once closed)
			info include account #, holder info, opening and closing date, and name of employee responsible
		deposit or withdraw money from a member account with permission/approval
		search accounts by account #, member name, or member phone number
*/

/* BEAR BANK MEMBER
	if the user logs into a bank membership account they will need to be able to:
		have more than one account
		change thier login password
		login using their member ID and password (able to see all their accounts)
		see a summery of last login date and time after successful login
		review/check all transactions made by their account within a specified range of days (up to us to choose how long)
*/

/* DAILY CHECKING ACCOUNT
	if the user opens this type of account the rules applied are:
		no monthly fees and no interest
*/

/* DAILY SAVINGS ACCOUNT
	if the user opens this type of account the rules applied are:
		not monthly fees and a "variable daily interest rate set by the bank officials"
*/

/*CERTIFICATE OF DEPOSIT
	if the user opens this type of account the rules applied are:
		fixed term (length), fixed-rate (interest?)
		early cancellation will result in a penalty fee based on the number of days remaining in the term and no interest will be paid out
*/

/*FUTURE ACCOUNTS
	In the instruction he says there may be new accounts in the future that will feature:
		a monthly fee
		fixed or variable interest rate
		penalty/service fees
	I think we should include an account type that is not implemented in the program but has the ability to be. In the accounts header file, we would make
	a function (newAccountType of something) that will not be included in this .cpp file. It can allow the user to choose the name through a string, have 
	an applied monthly fee, and then allow the user the option to include the type of interest and the rate, as well as if there is fees and what that would
	amount to. 
*/

