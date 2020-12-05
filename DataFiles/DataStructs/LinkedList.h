#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node<T>* next; //points to next value
    Node<T>* prev; //points to previous value
};

template <class T>
class LinkedList
{
private:
    Node<T>* head; //first node
    Node<T>* tail; //last node
    int maxCapacity; //helps institute max capacity, if wanted
    int currentItems; //helps prevent adding items beyond max capacity

public:
    LinkedList(int max = -1);
    LinkedList(const LinkedList& list); //deep copy constructor, but it's easier to use 'list = otherList' for deep copying
    ~LinkedList();

    bool isFull();
    bool isEmpty();
    void push(T itemValue); //adds on to beginning of linked list
    void append(T itemValue); //adds on directly to end of the linked list
    void remove(T itemValue);
    void delFirst(); //deletes the first node
    void delLast(); //deletes the last node
    bool search(T& itemValue);
    void peekFirst(T& item); //makes argument take head's value
    void peekLast(T& item); //makes argument take tail's value
    void display(); //displays from head to tail
    void rDisplay(); //displays from tail to head
    int size();
    void clear(); //removes all values in the linked list
    void operator = (const LinkedList& list); //deep copy esque for assignment operator overriding, usful for copy constructors of other classes invloving a linked list member
};

template <class T>
LinkedList<T>::LinkedList(int max) //the default argument is taken care of above
{
    head = nullptr;
    tail = nullptr;
    maxCapacity = max;
    currentItems = 0; //nothing initially
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
    head = nullptr;
    tail = nullptr;
    currentItems = 0;
    maxCapacity = list.maxCapacity;

    Node<T>* nodePtr = list.head;
    while (nodePtr != nullptr)
    {
        append(nodePtr->value); //adds new node to the current list
        nodePtr = nodePtr->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* nodePtr = head; //for traversing the list
    Node<T>* delNode = nullptr;

    while (nodePtr != nullptr)
    {
        delNode = nodePtr;
        nodePtr = nodePtr->next; //goes on to next node
        delete delNode;
    }
    delNode = nullptr;

    head = nullptr;
    tail = nullptr;
}

template <class T>
bool LinkedList<T>::search(T& itemValue)
{
    if (!isEmpty())
    {
        Node<T>* nodePtr = head;
        while (nodePtr->value != itemValue)
        {
            nodePtr = nodePtr->next;
            if (!nodePtr) //if reached the end
            {
                return false;
            }
        }
        itemValue = nodePtr->value; //only assigned a different value if found
        return true;
    }
    else
    {
        return false;
    }

}

template <class T>
void LinkedList<T>::push(T itemValue)
{
    if (isFull())
    {
        cout << "The list is full" << endl;
    }
    else
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = itemValue;
        newNode->prev = nullptr;

        if (isEmpty())
        {
            head = newNode;
            head->next = nullptr;
            tail = newNode; //head and tail are same Node with 1 element
            tail->next = nullptr;
        }
        else
        {
            Node<T>* oldHead = head;
            head = newNode;
            oldHead->prev = head;
            head->next = oldHead;
        }
        currentItems++;
    }
}

template <class T>
void LinkedList<T>::append(T itemValue)
{
    if (isFull())
    {
        cout << "The list is full" << endl;
    }
    else
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = itemValue;
        newNode->next = nullptr;

        if (head == nullptr) //if the list is empty
        {
            head = newNode;
            head->prev = nullptr;
            tail = newNode; //beginning and end point to same node since only one node exists 
            tail->next = nullptr;
            tail->prev = nullptr;
        }
        else
        {
            Node<T>* oldTail = tail;
            tail = newNode;
            newNode->prev = oldTail;
            oldTail->next = tail;
        }
        currentItems++;
    }
}

template <class T>
void LinkedList<T>::remove(T itemValue)
{
    if (isEmpty())
    {
        cout << "No values in the list. Unable to remove." << endl;
    }
    else
    {
        Node<T>* nodePtr = head;
        while (nodePtr->value != itemValue)
        {
            nodePtr = nodePtr->next;
            if (nodePtr == nullptr)
            {
                cout << "Unable to find the value" << endl;
                return; 
            }
        }

        if (nodePtr == head)        //first node is to be deleted
        {
            delFirst();
        }
        else
        {
            //pointers to reconnect the linked list
            Node<T>* before = nodePtr->prev;
            before->next = nodePtr->next;

            if (nodePtr == tail)
            {
                tail = before;
            }

            delete nodePtr;
            nodePtr = nullptr;
            currentItems--;
        }
    }
}

template <class T>
void LinkedList<T>::delFirst()
{
    if (isEmpty())
    {
        cout << "List is empty. Unable to remove value." << endl;
    }
    else
    {
        Node<T>* delNode = head;
        if (head == tail) //only one node
        {
            delete delNode;
            tail = nullptr;
            head = nullptr;
        }
        else //more than one node 
        {
            head = delNode->next;
            head->prev = nullptr;
            delete delNode;
        }
        delNode = nullptr;
        currentItems--;
    }
}

template <class T>
void LinkedList<T>::delLast()
{
    if (isEmpty())
    {
        cout << "List is empty. Unable to remove value." << endl;
    }
    else
    {
        Node<T>* delNode = tail;
        if (delNode == head) //only one node
        {
            delete delNode;
            tail = nullptr;
            head = nullptr;
        }
        else //more than one node
        {
            tail = delNode->prev;
            tail->next = nullptr;
            delete delNode;
        }
        delNode = nullptr;
        currentItems--;
    }
}

template <class T>
void LinkedList<T>::peekFirst(T& item)
{
    if (isEmpty())
    {
        cout << "List is empty. Unable to find value." << endl;
    }
    else
    {
        item = head->value;
    }
}

template <class T>
void LinkedList<T>::peekLast(T& item)
{
    if (isEmpty())
    {
        cout << "List is empty. Unable to find value." << endl;
    }
    else
    {
        item = tail->value;
    }
}

template <class T>
void LinkedList<T>::display()
{
    if (!isEmpty())
    {
        Node<T>* nodePtr = head; 
        while (nodePtr != nullptr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next; //traverse forward a node
        }
        cout << endl;
    }
    else
    {
        cout << "The list is empty. Unable to display values." << endl;
    }
}

template <class T>
void LinkedList<T>::rDisplay()
{
    if (!isEmpty())
    {
        Node<T>* nodePtr = tail;
        while (nodePtr != nullptr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->prev; //traverse forward a node
        }
        cout << endl;
    }
    else
    {
        cout << "The list is empty. Unable to display values." << endl;
    }
}

template <class T>
bool LinkedList<T>::isFull()
{
    bool status = (maxCapacity == currentItems) ? true : false;
    return status;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    bool status = (currentItems == 0) ? true : false;
    return status;
}

template <class T>
int LinkedList<T>::size()
{
    return currentItems;
}

template <class T>
void LinkedList<T>::clear()
{
    //will delete each node in the list
    Node<T>* nodePtr = head; 
    Node<T>* delNode = nullptr;

    while (nodePtr != nullptr)
    {
        delNode = nodePtr;
        nodePtr = nodePtr->next; 
        delete delNode;
    }
    delNode = nullptr;

    //now reset initial values
    head = nullptr;
    tail = nullptr;
    currentItems = 0;
}


template <class T>
void LinkedList<T>::operator = (const LinkedList& list)
{
    clear(); //clear existing list
    maxCapacity = list.maxCapacity;

    Node<T>* nodePtr = list.head;
    while (nodePtr != nullptr)
    {
        append(nodePtr->value); //append the node to the list
        nodePtr = nodePtr->next;
    }
}
#endif