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
		struct ListNode *next;
	};

	ListNode *head;

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
	void openAccount();		//open a member's account(s)
	void closeAccount();	//close a member's account(s)
};

template <class T>
void BankOfficials<T>::hireEmployee(T newValue)
{
	ListNode* newNode;	//a new node
	ListNode* nodePtr;	//node to traverse the list
	ListNode* prevNode = nullptr;	//pointer to previous node

	//create a new node and store the new value there
	newNode = new ListNode;
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
		while (nodePtr != nullptr)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		prevNode->next = newNode;
		newNode->next = nodePtr;
	}
}

template <class T>
void BankOfficials<T>::loginIn(T value)
{
	ListNode* nodePtr;	//node to traverse the list

	nodePtr = head;

	if (nodePtr->value == value)	//if the user is the first node
	{
		cout << nodePtr->value << endl;
	}
	else  //if the user is not the first node
	{
		while (nodePtr->value != value)
		{
			nodePtr = nodePtr->next;
		}

		cout << nodePtr->value << endl;
		//include a way to check if the name entered is not on the list
	}

}

template <class T>
void BankOfficials<T>::fireEmployee(T value)
{
	ListNode* nodePtr;	//node to traverse the list
	ListNode* tempNode;	//pointer to temporary node
	ListNode* prevNode = nullptr; //pointer to previous node --might not need

	if (isEmpty())
	{
		cout << "Invalid operation. There must be at least one employee working.\n";
		return;
	}
	else
	{
		//need a check if deleting employee will result in 0
		nodePtr = head;		//nodePtr is assigned to the head
		tempNode = nullptr;		//tempNode is assigned nullptr

		if (nodePtr->value == value)	//if the node to be deleted is the head
		{
			tempNode = head;
			nodePtr = nodePtr->next;
			cout << "Removing " << tempNode->value << " from employee database" << endl;
			delete tempNode;
			head = nodePtr;		//needed a tracker to reassign head bc delete made it null
			return;
		}
		else  //if the first node is not to be deleted
		{
			while (nodePtr->value != value)		//while loop to traverse the list
			{
				prevNode = nodePtr;		//prevNode takes on nodePtr
				nodePtr = nodePtr->next;	//nodePtr traverses the list
			}

			tempNode = nodePtr;
			nodePtr = nodePtr->next;
			cout << "Removing " << tempNode->value << " from employee database" << endl;
			delete tempNode;
			prevNode->next = nodePtr;
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

template <class T>
BankOfficials<T>::~BankOfficials()
{
	ListNode* nodePtr;  // To traverse the list
	ListNode* nextNode; // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}
#endif
