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
	when trying to open or close account, traverse the linked list to see if the user is in the employee list -- might not be in this file

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
	~BankOfficials();	//check submission requirements to see if this is needed

	//Linked List operations
	void hireEmployee(T);	//add employee to the list
	void fireEmployee(T);	//remove employee from the list
	void loginIn(T);		//search employee --don't think this will be implemented here
	bool isEmpty();			//check if list is empty
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
		prevNode = nullptr;

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

template <class T>
void BankOfficials<T>::fireEmployee(T value)
{
	listNode* nodePtr;	//node to traverse the list
	listNode* tempNode;	//pointer to previous node

	if (isEmpty())
	{
		cout << "Invalid operation. There must be at least one employee working.\n";
		return;
	}
	else
	{
		nodePtr = head;		//nodePtr is assigned to the head
		tempNode = nullptr;		//tempNode is assigned nullptr

		if (nodePtr->value == value)	//if the node to be deleted is the head
		{
			tempNode = nodePtr;	//tempNode is assigned the value to be deleted
			nodePtr = nodePtr->next;
			delete tempNode;		//delete the value from the list
			tempNode->next = nullptr;
			return;
		}
		else  //if the first node is not to be deleted
		{
			while (nodePtr->value != value)		//while loop to traverse the list
			{
				tempNode = nodePtr;		//tempNode takes on nodePtr
				nodePtr = nodePtr->next;	//nodePtr traverses the list
			}

			tempNode = nodePtr;		//tempNode is assigned the value to be deleted
			nodePtr = nodePtr->next;
			delete tempNode;		//delete the value from the list
			tempNode->next = nullptr;
			return;
		}
	}
}

template <class T>
bool BankOfficials<T>::isEmpty()
{
	bool unoccupied;

	if (head == nullptr)
	{
		unoccupied = true;
	}
	else
	{
		unoccupied = false;
	}

	return unoccupied;
}
#endif
