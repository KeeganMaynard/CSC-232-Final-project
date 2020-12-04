#ifndef ACCOUNTCHART_H
#define ACCOUNTCHART_H
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
//#include "Encryption.h"
using namespace std;

struct accountEntry
{
	string key;
	string info;

	accountEntry();
	accountEntry(string keyValue);
	accountEntry(string keyValue, string infoValue);
	//create operator overloads
};

class AccountChart
{
private:
	LinkedList<accountEntry>* dictionary;

	unsigned int maximum;	//tracks the max size of the dictionary
	unsigned int usedLocal;	//tracks the number of used locations
	unsigned int count;		//tracks the number of keys
	double loadFactor;
	float threshold;		//determines the loadFactor threshold for efficiency 
	int collisions;			//tracks the number of max collisions

protected:
	void update();			//updates the loadFactor
	void resize();			//increases the size to keep load factor below threshold

public:
	//constructor and destructor
	AccountChart();
	~AccountChart();

	bool isEmpty();						//returns if the dictionary is empty
	void insert(accountEntry value);	//adds entry to the chart/file
	void del(string key);				//removes a key value pair from the file
	void display();
	string find(string key);			//returns the info of the key
	void update(string key, string newInfo); //updates information for the given key
	void saveInfo(string fileID);		//saves the info to the appropriate file
	void buildChart(string fileID);		//
	void refresh();						//rebuilding the accounts to compute interest
};
#endif