//The main .cpp file for the project

#include "BankOfficials.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool run;
	string userInput, exit;

	while (run)
	{
		//do you guys want to ask the user what type of account they are logging into, or should we just have them enter their information and then search
		//each data structure for thier information
		cout << "Login to your account type:\n [1] System Administrator\n [2] Bank Official\n [3] Bank Member" << endl;
		getline(cin, userInput);
		//will need an input to determine if the user is new or returning...
		if (userInput == "1")
		{
			cout << "Return to main or exit?" << endl;
			getline(cin, exit);
			if (exit == "exit")
			{
				run = false;
			}
		}
		else if (userInput == "2")
		{
			cout << "Return to main or exit?" << endl;
			getline(cin, exit);
			if (exit == "exit")
			{
				run = false;
			}
		}
		else if (userInput == "3")
		{
			cout << "Return to main or exit?" << endl;
			getline(cin, exit);
			if (exit == "exit")
			{
				run = false;
			}
			//find a better way to end the program when the user wants
		}
	}

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