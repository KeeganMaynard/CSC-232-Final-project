#include "AccountChart.h"
using namespace std;

//operator overload functions

//constructors
accountEntry::accountEntry()
{
	key = "";
	info = "";
}

accountEntry::accountEntry(string keyValue)
{
	key = keyValue;
	info = "default";
}

accountEntry::accountEntry(string keyValue, string infoValue)
{
	key = keyValue;
	info = infoValue;
}

AccountChart::AccountChart()
{
	maximum = 5;	//default value
	usedLocal = 0;
	count = 0;
	loadFactor = 0.0;
	threshold = .5;	//default value
	collisions = 0;
	dictionary = new LinkedList<accountEntry>[maximum];
}

//destructor
AccountChart::~AccountChart()
{
	delete dictionary[];
	dictionary = nullptr;
}

//functions
bool AccountChart::isEmpty()
{
	bool empty = (count == 0) ? true : false;
	return empty;
}

void AccountChart::insert(accountEntry value)
{
	unsigned int index = 0; //encryption class getindex

	if (dictionary[index].isEmpty())
	{
		usedLocal++;
	}

	dictionary[index].append(value);	//adding the value to the linked list at index
	count++;
	update();

	if (dictionary[index].size() > collisions)
	{
		collisions = dictionary[index].size();
	}

	if (loadFactor > threshold)
	{
		resize();		//change the size of the dictionary when the load factor becomes too high
	}
}

void AccountChart::del(string key)
{
	if (isEmpty())
	{
		cout << "There are no values to remove." << endl;
	}
	else
	{
		unsigned int index = 0; //encryption call getindex
		accountEntry remove(key);		//local variable assigned to the key value

		int size = dictionary[index].size();
		dictionary[index].remove(remove);
		if (size != dictionary[index].size())
		{
			count--;
		}
	}
}

void AccountChart::display()
{
	for (int i = 0; i < maximum; i++)
	{
		if (!dictionary[i].isEmpty())
		{
			cout << "Index: " << i << ". Size: " << dictionary[i].size() << endl;	//display the size of the index
			//dictionary[i].display();  //add function to the LinkedList.h
		}
	}
}

string AccountChart::find(string key)
{
	unsigned int index = 0; //encryption call getIndex
	accountEntry value(key);	//local variable assigned to the key
	bool found = dictionary[index].search(value);	//local variable to return if the value was found or not

	if (!found)
	{
		return "Value not found.";
	}
	else
	{
		return value.info;
	}
}

void AccountChart::update(string key, string newInfo)
{
	unsigned int index = 0; //encryption call getIndex
	accountEntry previous(key), newEntry(key, newInfo);	//storing the old and new info to local variables
	dictionary[index].remove(previous);
	dictionary[index].append(newEntry);
}

void AccountChart::saveInfo(string fileID)
{
	//encryption call to set the position in the file to 0
	ofstream outFile(fileID);
	accountEntry value;

	if (outFile)
	{
		for (int i = 0; i < maximum; i++)
		{
			while (!dictionary[i].isEmpty())	//while the dictionary is not empty at the index i
			{
				//dictionary[i].call to linked list delete the first value
				//string to store value into the key and the info
				//outFile << encryption call to encrypt the string 
			}
		}
	}
	else
	{
		cout << "The file: " << fileID << " cannot be altered at this time." << endl;
		abort();
	}
	outFile.close();
}

void AccountChart::buildChart(string fileID)
{
	//encryption call to set the position in the file to 0
	ifstream inFile;
	inFile.open(fileID);

	if (inFile)
	{
		string line = "";
		while (getline(inFile, line))
		{
			//code to create substrings, decrypt the code, and enter the key and subtring
			//insert(the account entry create)
		}
	}
	else
	{
		cout << "The file: " << fileID << " could not be accessed at this time." << endl;
	}
	inFile.close();
}

void AccountChart::refresh()
{
	for (int i = 0; i < maximum; i++)
	{
		if (!dictionary[i].isEmpty())   //if the dictionary is not empty at index i
		{
			//similar to dynamic arrays, create a temporary linked list to store the values, then clear the dictionary, then restore the values to the dictionary
		}
	}
}