//The main .cpp file for the project

#include "UserTypes/BankOfficials.h"
#include "UserTypes/SystemAdmin.h"
#include "UserTypes/UserAccounts.h"
#include "Data Structs/DataController.h"
#include "UserTypes/Users.h"
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

	while (run)
	{
		userInput = accountAge();

		if (userInput == "1")
		{
			int type = accountType();

			switch (type) {

			case 1://System Admin
			{
				string ID = "", password = "", valid = "";
				cout << "Enter System administrator login ID and password: " << endl;
				cout << "Username: ";
				getline(cin, ID);
				cout << "Password: ";
				getline(cin, password);
				cout << endl;

				valid = DataController::validLogin(ID, password);
				if (valid == "false")
				{
					cout << "Invalid information entered. Please try again." << endl;
				}
				else
				{
					//log into system admin account
				}
				break;
			}

			case 2://Bank Official
			{
				string ID = "", password = "", valid = "";
				cout << "Enter Bank official login ID and password: " << endl;
				cout << "Username: ";
				getline(cin, ID);
				cout << "Password: ";
				getline(cin, password);
				cout << endl;

				valid = DataController::validLogin(ID, password);
				if (valid == "false")
				{
					cout << "Invalid information entered. Please try again." << endl;
				}
				else
				{
					//log into bank official account
				}

				break;
			}

			case 3://Bank Member
			{
				string ID = "", password = "", valid = "";
				cout << "Enter Bank member login ID and password: " << endl;
				cout << "Username: ";
				getline(cin, ID);
				cout << "Password: ";
				getline(cin, password);
				cout << endl;

				valid = DataController::validLogin(ID, password);
				if (valid == "false")
				{
					cout << "Invalid information entered. Please try again." << endl;
				}
				else
				{
					//log into bank member account
				}
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
				//gather user information for bank officials
				cout << "Enter the require System administrator login information:";
				break;
			}
			case 2://new bank member account
			{
				string firstName = "", lastName = "", phone = "", address = "", ID = "", password = "";
				//gather user information for bank members
				cout << "To create an account, please enter your personal information:\n";
				cout << "First name: ";
				getline(cin, firstName);
				cout << "\nLast name: ";
				getline(cin, lastName);
				cout << "\nPhone Number: ";
				getline(cin, phone);
				cout << "\nAddress: ";
				getline(cin, address);

				//create new account
				bool valid;
				cout << "Please enter your user ID and a secure password: ";
				cout << "User ID: ";
				getline(cin, ID);

				//check to make sure user ID is not already in use
				valid = DataController::availableUser(ID);
				while (valid == false)
				{
					cout << "That user ID is already in unavailable. Please enter a different ID: ";
					getline(cin, ID);
				}

				//create the password
				cout << "\nPasword: ";
				getline(cin, password);

				//create the member to save to the file
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
			cout << "Invalid input. Please try again" << endl;
			continue;
		}
	}

	//save all the changes made to files
	return 0;
}

string encrypt(string s) { //Basic string encryption
	for (int i = 0; i < s.length(); i++) {
		s[i] = s[i] + 45;
	}
	return s;
}

string decrypt(string s) { //Decryption key for strings
	for (int i = 0; i < s.length(); i++) {
		s[i] = s[i] - 45;
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

