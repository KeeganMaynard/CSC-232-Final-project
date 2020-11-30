//Header file for the bank employees to perform their tasks with the necessary restrictions and abilities
#ifndef BANKOFFICIALS_H
#define BANKOFFICIALS_H
#include <iostream>
using namespace std;

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

bank employees must be able ot deposit or withdraw money from an account with the approval of the customer
	customer must have some form of authentication in order to proceed

bank employees must be able to search accounts
	search by account # or account holder info
*/

// CODE IMPLEMENTATION BELOW

template <class T>
class BankOfficials
{
private:

	struct ListNode
	{
		T value;
		struct listNode *next;
	};

	listNode *head;

public:
	//constructor
	BankOfficials()
	{
		head = nullptr;
	}
	//destructor
	~BankOfficials();

	//Linked List operations
	void hireEmployee(T);	//add employee to the list
	void fireEmployee(T);	//remove employee from the list
	void loginIn(T);		//search employee
};

template <class T>
void BankOfficials<T>::hireEmployee(T newValue)
{
	listNode* newNode;	//a new node
	listNode* nodePtr;	//node to traverse the list
	listNode* prevNode;	//pointer to previous node

	//create a new node and store the new value there
	newNode = new listNode;
	newNode->value = newValue;

	if (!head)	//if there are no employees
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else   //else add the node to the end of the list
	{
		//start at the head
		nodePtr = head;

		//traverse the nodes
		while (nodePtr != nodePtr)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		prevNode->next = newNode;
		newNode->next = nodePtr;
	}
}
#endif
