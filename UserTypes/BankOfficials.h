//Header file for the bank employees to perform their tasks with the necessary restrictions and abilities
#ifndef BANKOFFICIALS_H
#define BANKOFFICIALS_H
#include "Users.h"

class BankOfficials : public Users
{
private:
	string officialStatus;
public:
	BankOfficials();
	BankOfficials(string name, string ID, string password, string type, string login);
	BankOfficials(string name, string ID, string password, string type);

	void saveUser();
	void createUser(string fileID);

	void newMemberUser();	//need to access stored members
	void searchID(string ID);
	void searchFirstName(string firstName);
	void searchLastName(string lastName);
	void searchAccount(string accountNum);
	void searchPhone(string phoneNum);
	void searchAddress(string address);

	string getStatus();
	void setStatus(string status);
};
#endif


/* DATA STRUCTURE FOR BANK OFFICIALS
Data structure to store bank employees -- assume there is a minimum of 10 employees and a maximum of 25
	use link based array -- there will not be an extremely large amount of employees, so search time doesn't have a huge impact, and the number of
	employees is not restricted so the linked implementation will allow removing and adding employees without shifting the array.
*/

/* TASKS/ABILITIES/RESTRICTIONS
bank employees must be able to open or close an account
	accounts that are closed must remain saved so they can be reopened at a later date by bank officials only
		account #
		account holder info
		opening and closing date
		name of employee involved in opening/closing account
	when trying to open or close account, traverse the linked list to see if the user is in the employee list -- might not be in this file

bank employees must be able ot deposit or withdraw money from an account with the approval of the customer
	customer must have some form of authentication in order to proceed

bank employees must be able to search accounts
	search by account # or account holder info
*/
