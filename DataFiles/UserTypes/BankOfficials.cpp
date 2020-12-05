#include "BankOfficials.h"

BankOfficials::BankOfficials()
{
	//default constructor
	;
}

BankOfficials::BankOfficials(string name, string ID, string password, string type, string login) : Users(name, ID, password, type, login)
{
	//set the status of the account
}

BankOfficials::BankOfficials(string name, string ID, string password, string type) : Users(name, ID, password, type)
{
	//set the status of the account
}

string BankOfficials::getStatus()
{
	return officialStatus;
}

void BankOfficials::setStatus(string status)
{
	officialStatus = status;
}

void BankOfficials::saveUser()
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
		//include the status of the account
	}
	else
	{
		cout << "The file: " << userID + ".txt" << " is unavailable at this time." << endl;
	}

	outFile.close();
}

void BankOfficials::createUser(string fileID)
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
		//set status of the official account
	}
	else
	{
		cout << "The file: " << fileID << " cannot be read from at this time." << endl;
	}

	inFile.close();
}

void BankOfficials::newMemberUser()
{
	//function to create a new member account
}

void BankOfficials::searchID(string ID)
{
	//function to search a member by their account ID
}

void BankOfficials::searchFirstName(string firstName)
{
	//function to search a member by their first name
}

void BankOfficials::searchLastName(string lastName)
{
	//function to search a member by their last name
}

void BankOfficials::searchAccount(string accountNum)
{
	//function to search a member by their accout number
}

void BankOfficials::searchPhone(string phoneNum)
{
	//function to search a member by thier phone number
}

void BankOfficials::searchAddress(string address)
{
	//function to search a member by their address
}