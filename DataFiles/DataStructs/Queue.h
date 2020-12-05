#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include "Encryption.h"
#include <iostream>
#include <fstream>
using namespace std;

class Queue
{
private:
    LinkedList<string> list;
public:
    Queue(int max = -1);

    void enqueue(string item);
    bool dequeue(string& item);
    bool peekFirst(string& item);
    bool isEmpty();
    bool isFull();
    void clear();
    void display();
    void saveQueue();
    void buildQueue();
};

Queue::Queue(int max)
{
    max = (max < 1) ? -1 : max;
    list = LinkedList<string>(max);
}

bool Queue::peekFirst(string& item)
{
    if (!isEmpty())
    {
        list.peekFirst(item); //item takes head node's value
        return true;
    }
    return false;
}

void Queue::enqueue(string item)
{
    list.append(item);
}

bool Queue::dequeue(string& item)
{
    if (!isEmpty())
    {
        list.peekFirst(item);
        list.delFirst(); //deleteing head node
        return true;
    }
    return false;
}

void Queue::clear()
{
    list.clear();
}

bool Queue::isEmpty()
{
    return list.isEmpty();
}

bool Queue::isFull()
{
    return list.isFull();
}

void Queue::display()
{
    list.displayList();
}

void Queue::saveQueue() 
{
    Encryption::positionInFile = 0;
    LinkedList<string> List = list;     //deep copy
    string text = "";
    ofstream outFile("AccountData/RequestedAccounts.txt"); //needs to be updated

    if (outFile)
    {
        while (!List.isEmpty())
        {
            List.peekFirst(text);
            List.delFirst();
            outFile << Encryption::encrypt(text) << endl;
        }
    }
    else
    {
        cout << "Information could not be saved at this time." << endl;
    }
    outFile.close();
}

void Queue::buildQueue()
{
    list.clear();
    string text = "";
    ifstream inFile;
    inFile.open("AccountData/RequestedAccounts.txt");       //will have to updated later
    Encryption::positionInFile = 0;

    if (inFile)
    {
        while (getline(inFile, text))
        {
            text = text.substr(0, text.rfind("\r")); //removing carriage return
            text = Encryption::decrypt(text); //making ledgible
            list.append(text); //puts to end of list, thus preserving queue order
        }
    }
    else
    {
        cout << "Information could not be saved at this time." << endl;
    }
}
#endif