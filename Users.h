//Parent class header file for the three types of users
#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Users
{
public:
	Users(){}
	Users(string name, string ID, string password, string type, string login);
	Users(string name, string ID, string password, string type);

	string getName();
	string getID();
	string getPassword();
	string getUserType();

	void setName(string newName);
	void setID(string newID);
	void setPassword(string newPass);
	void setUserType(string type);

	bool validLogin(string newName, string newPass);

	virtual void saveUser();
	virtual void createUser(string fileID);
protected:
	string userName;
	string userID;
	string userPass;
	string userType;
};
#endif