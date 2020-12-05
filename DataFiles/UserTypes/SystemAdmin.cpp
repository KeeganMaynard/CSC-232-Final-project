#include "SystemAdmin.h"

SystemAdmin::SystemAdmin()
{
	//default constructor
	;
}

SystemAdmin::SystemAdmin(string name, string ID, string password, string type, string login) : Users(name, ID, password, type, login)
{
	;
}

SystemAdmin::SystemAdmin(string name, string ID, string password, string type) : Users(name, ID, password, type)
{
	;
}

void SystemAdmin::resetPassword(string ID, string newPass)
{
	//Function to reset user passwords
}

string SystemAdmin::showUserID(string accountNum)
{
	//function to return a string of user account info based on search
}

void SystemAdmin::createOfficial(string fullName, string ID, string password)
{
	//function to create a new official
}

void SystemAdmin::deleteOfficial()
{
	//function to remove an official
}

void SystemAdmin::activeOfficial()
{
	//function to set the status of official accounts to active
}

void SystemAdmin::inactiveOfficial()
{
	//function to set the status of official account to inactive
}

void SystemAdmin::removeUser(string fileID)
{
	ofstream outFile(fileID);
	if (outFile)
	{
		outFile << "";
	}
	else
	{
		cout << "The file: " << fileID << " could not be altered at this time.";
	}
	outFile.close();
}