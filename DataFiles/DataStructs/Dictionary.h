#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
#include <fstream>
#include "Encryption.h"
#include "LinkedList.h"
using namespace std;

struct accountEntry
{
    string key;
    string info; 

    accountEntry();
    accountEntry(string keyValue);
    accountEntry(string keyValue, string infoValue);

    //operator overloads to insert and remove values 
    bool operator == (const accountEntry& item);
    bool operator != (const accountEntry& item); 
};

class AccountChart
{
private:
    LinkedList<accountEntry>* accountDict;

    //Used for statistics of list and hashing
    unsigned int max;
    unsigned int usedLocals;
    unsigned int totalKeys;
    double loadFactor; 
    float loadThreshold;
    int maxCollisions;

protected:
    void updateFactor();
    void resize(); //resize the list when the load factor is too high

public:
    AccountChart();
    ~AccountChart();
    bool isEmpty();
    void insert(accountEntry newAccount);
    void del(string key);
    string search(string key); //returns all info of value, if found
    bool canFind(string key); //checks if a value exists
    void display();
    void updateInfo(string key, string newInfo);
    void saveInfo(string fileID);
    void buildDict(string fileID);
    void getStatistics();
    void refresh(); //rebuild all accounts in the linked list, computes interest
};
#endif