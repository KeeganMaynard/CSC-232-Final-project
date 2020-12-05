/*
Implementation file for the Dictionary object
*/
#include "Dictionary.h"

ostream& operator << (ostream& os, const accountEntry value)
{
    os << value.key << ": " << value.info;
    return os;
}

bool accountEntry::operator == (const accountEntry& value)
{
    bool status = (key == value.key) ? true : false;
    return status;
}

bool accountEntry::operator != (const accountEntry& value)
{
    bool status = (key != value.key) ? true : false;
    return status;
}

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
    max = 10;           //default value
    usedLocals = 0;
    totalKeys = 0;
    loadFactor = 0.0;
    loadThreshold = .9; //default value
    maxCollisions = 0;
    accountDict = new LinkedList<accountEntry>[max];
}

AccountChart::~AccountChart()
{
    delete[] accountDict; //linked list contains the destructor
    accountDict = nullptr;
}

void AccountChart::updateFactor()
{
    double usedIndex = totalKeys;       //double is used to store decimals 
    loadFactor = usedIndex / max; 
}

bool AccountChart::isEmpty()
{
    bool status = (totalKeys == 0) ? true : false;
    return status;
}

void AccountChart::insert(accountEntry newAccount)
{
    unsigned int index = Encryption::getIndex(newAccount.key, max); //hashing the entry's key % dict size to find where it belongs

    if (accountDict[index].isEmpty())
    {
        usedLocals++;
    }

    accountDict[index].append(newAccount); //adding to that index's linked list
    totalKeys++;
    updateFactor();
    if (accountDict[index].size() > maxCollisions)
    {
        maxCollisions = accountDict[index].size();
    }

    if (loadFactor > loadThreshold)
    {
        resize();
    }
}

string AccountChart::search(string key)
{
    unsigned int index = Encryption::getIndex(key, max);
    accountEntry value(key);
    bool found = accountDict[index].search(value);
    if (!found)
    {
        return "false";
    }
    else
    {
        return value.info;
    }
}

void AccountChart::del(string key)
{
    if (isEmpty())
    {
        cout << "The index is empty." << endl;
    }
    else
    {
        unsigned int index = Encryption::getIndex(key, max); //hashing the entry's key % dict size to find where it belongs
        accountEntry toDel(key);

        int currentSize = accountDict[index].size();
        accountDict[index].remove(toDel);
        if (currentSize != accountDict[index].size())
        {
            totalKeys--;
        }
    }
}

void AccountChart::updateInfo(string key, string newInfo)
{
    unsigned int index = Encryption::getIndex(key, max); //hashing the entry's key % dict size to find where it belongs
    accountEntry oldInfo(key), newEntry(key, newInfo);      //cannot have newInfo as a variable to match
    accountDict[index].remove(oldInfo);
    accountDict[index].append(newEntry);
}

bool AccountChart::canFind(string key)
{
    unsigned int index = Encryption::getIndex(key, max);
    accountEntry value(key);
    bool found = accountDict[index].search(value);
    return found;
}

void AccountChart::resize()
{
    LinkedList<accountEntry>* tempDict = new LinkedList<accountEntry>[max * 2];
    unsigned int UsedIndicies = 0;
    int tempCollisions = 0;

    for (int i = 0; i < max; i++) //for each index in array
    {
        while (!accountDict[i].isEmpty()) //if not empty, need to rehash each entry into tempDict
        {
            accountEntry value;
            accountDict[i].peekFirst(value); //value takes on first element in linked list's value
            accountDict[i].delFirst();

            unsigned int index = Encryption::getIndex(value.key, max * 2); //finding where value needs to go in new dict
            if (tempDict[index].isEmpty())
            {
                UsedIndicies++;
            }
            tempDict[index].append(value); //adding value to new dict
            if (tempDict[index].size() > tempCollisions)
            {
                tempCollisions = tempDict[index].size();
            }
        }
    }

    //update private variables
    max *= 2;
    delete[] accountDict;
    accountDict = tempDict;
    tempDict = nullptr;
    usedLocals = UsedIndicies;
    maxCollisions = tempCollisions;
    updateFactor();
}

void AccountChart::display()
{
    for (int i = 0; i < max; i++)       //for all indicies
    {
        if (!accountDict[i].isEmpty())
        {
            cout << "Index: " << i << ". Size: " << accountDict[i].size() << endl;
            accountDict[i].displayList();
        }
    }
}

void AccountChart::getStatistics()
{
    unsigned int avaliableLocals = (loadThreshold * max) - totalKeys;
    double locals = usedLocals;
    double usagePercent = (locals / max) * 100;
    cout << endl;
    cout << "Total capacity: " << max << endl;
    cout << "Total keys stored: " << totalKeys << endl;
    cout << "Total indicies used: " << locals << endl;
    cout << "Load factor: " << loadFactor << endl;
    cout << "Load threshold: " << loadThreshold << endl;
    cout << "Avaliable entries before resizing: " << avaliableLocals << endl;
    cout << "Max Collisions in a single index: " << maxCollisions - 1 << endl;
    cout << "Array index usage: " << usagePercent << "%" << endl;
}

void AccountChart::saveInfo(string fileID)
{
    Encryption::positionInFile = 0;
    ofstream outFile(fileID);
    accountEntry storedItem;
    if (outFile)
    {
        for (int i = 0; i < max; i++)
        {
            while (!accountDict[i].isEmpty())
            {
                accountDict[i].peekFirst(storedItem);
                accountDict[i].delFirst();
                string output = storedItem.key + "%#" + storedItem.info;
                outFile << Encryption::encrypt(output) << endl;
            }
        }
    }
    else
    {
        cerr << fileID << " cannot be accessed at this time." << endl;
        abort();
    }
    outFile.close();
}

void AccountChart::buildDict(string fileID)
{
    Encryption::positionInFile = 0;
    ifstream inFile;
    inFile.open(fileID);
    if (inFile)
    {
        string line = "";
        while (getline(inFile, line))
        {
            line = line.substr(0, line.rfind("\r")); //removing carriage return from .txt file
            line = Encryption::decrypt(line); //decrypting in order to read from
            string delim = "%#";
            string key = line.substr(0, line.find(delim));
            line = line.substr(line.find(delim) + delim.length(), string::npos);
            accountEntry entry(key, line);
            insert(entry);
        }
    }
    else
    {
        cout << fileID << " cannot be accessed at this time." << endl;
    }
    inFile.close();
}

void AccountChart::refresh()
{
    for (int i = 0; i < max; i++)
    {
        if (!accountDict[i].isEmpty())
        {
            const int size = accountDict[i].size();
            LinkedList<accountEntry> newList;

            for (int k = 0; k < size; k++)
            {
                accountEntry oldEntry;
                accountDict[i].peekFirst(oldEntry);
                accountDict[i].delFirst();

                //adding interest onto the account
                Account acctObj(oldEntry.key);
                string acctInfo = acctObj.updateInfo(); //reset info, changed with interest
                accountEntry newEntry(oldEntry.key, acctInfo);
                newList.append(newEntry);
            }

            accountDict[i] = newList; //deep copy new values
        }
    }
}