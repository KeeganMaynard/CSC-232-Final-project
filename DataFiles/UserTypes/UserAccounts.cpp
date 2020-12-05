#include "UserAccounts.h"

UserAccounts::UserAccounts()
{
	//default constructor
	;
}

UserAccounts::UserAccounts(string name, string ID, string password, string type, string login, string address, string phone) : Users(name, ID, password, type, login)
{
	memberAddress = address;
	memberPhone = phone;
}

UserAccounts::UserAccounts(string name, string ID, string password, string type, string address, string phone) : Users(name, ID, password, type)
{
	memberAddress = address;
	memberPhone = phone;
}

void UserAccounts::setAddress(string address)
{
	memberAddress = address;
}

void UserAccounts::setPhone(string phone)
{
	memberPhone = phone;
}

string UserAccounts::getAddress()
{
	return memberAddress;
}

string UserAccounts::getPhone()
{
	return memberPhone;
}

void UserAccounts::history(vector<string>accounts)
{
	//function to display the history of an account
}

void UserAccounts::saveUser()
{
	ofstream outFile(userID + ".txt");
	if (outFile)
	{
		outFile << userID << endl;
		outFile << userName << endl;
		outFile << userPass << endl;
		outFile << userType << endl;
		outFile << lastLogin << endl;
		outFile << lastActivity << endl;
		outFile << memberAddress << endl;
		outFile << memberPhone << endl;
	}
	else
	{
		cout << "The file: " << userID + ".txt" << " is unavailable at this time." << endl;
	}

	outFile.close();
}

void UserAccounts::createUser(string fileID)
{
	ifstream inFile;
	inFile.open(fileID);
	if (inFile)
	{
		string line = "";
		vector<string> userInfo = {};

		while (getline(inFile, line))
		{
			line = line.substr(0, line.find(" "));
			userInfo.push_back(line);	//adding user information to the vector
		}

		//set user info
		userID = userInfo[0];
		userName = userInfo[1];
		userPass = userInfo[2];
		userType = userInfo[3];
		lastLogin = userInfo[4];
		lastActivity = userInfo[5];
		memberAddress = userInfo[6];
		memberPhone = userInfo[7];
	}
	else
	{
		cout << "The file: " << fileID << " cannot be read from at this time." << endl;
	}

	inFile.close();
}

void UserAccounts::display()
{
	string name = userName, firstName = "", lastName = "";
	firstName = name.substr(0, name.find(" "));
	lastName = name.substr(name.find(" ") + 1, string::npos);
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Phone Number: " << memberPhone << endl;
	cout << "Address: " << memberAddress << endl;
}