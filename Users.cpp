//implementation for Users.h
#include "Users.h"

Users::Users()
{
	//Default constructor
	;
}

Users::Users(string name, string ID, string password, string type, string login)
{
	userName = name;
	userID = ID;
	userPass = password;
	userType = type;
	lastLogin = login;
	lastActivity = "No activity has been found for this account.";
}

Users::Users(string name, string ID, string password, string type)
{
	userName = name;
	userID = ID;
	userPass = password;
	userType = type;
	lastLogin = "This account has not been accessed before.";
}

string Users::getName()
{
	return userName;
}

string Users::getID()
{
	return userID;
}

string Users::getPassword()
{
	return userPass;
}

string Users::getUserType()
{
	return userType;
}

string Users::getPastLogin()
{
	return lastLogin;
}

string Users::getActivity()
{
	return lastActivity;
}

void Users::setName(string newName)
{
	userName = newName;
}

void Users::setID(string newID)
{
	userID = newID;
}

void Users::setPassword(string newPass)
{
	userPass = newPass;
}

void Users::setUserType(string type)
{
	userType = type;
}

void Users::setPastLogin(string login)
{
	lastLogin = login;
}

void Users::setActivity(string active)
{
	lastActivity = active;
}

bool Users::validLogin(string newName, string newPass, string time)
{
	if (userName == newName && userPass == newPass)
	{
		lastLogin = time;
		return true;
	}
	else
	{
		return false;
	}
}

void Users::saveUser()
{
	ofstream outFile(userID + ".txt");	//creates new file for user -- need folder for user info
	if (outFile)
	{
		//write user info to the file
		outFile << userID << endl;
		outFile << userName << endl;
		outFile << userPass << endl;
		outFile << userType << endl;
		outFile << lastLogin << endl;
		outFile << lastActivity << endl;
	}
	else
	{
		cout << "File " << userID + ".txt" << " is unavailable at this time." << endl;
	}

	outFile.close();
}

void Users::createUser(string fileID)
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
	}
	else
	{
		cout << "The file: " << fileID << " cannot be read from at this time." << endl;
	}

	inFile.close();
}