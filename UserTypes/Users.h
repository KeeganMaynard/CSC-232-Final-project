//Parent class header file for the three types of users
#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Users
{
protected:
	string userName;
	string userID;
	string userPass;
	string userType;
	string lastLogin;
	string lastActivity;
public:
	Users() {}
	Users(string name, string ID, string password, string type, string login);
	Users(string name, string ID, string password, string type);

	string getName();
	string getID();
	string getPassword();
	string getUserType();
	string getPastLogin();
	string getActivity();

	void setName(string newName);
	void setID(string newID);
	void setPassword(string newPass);
	void setUserType(string type);
	void setPastLogin(string login);
	void setActivity(string active);

	bool validLogin(string newName, string newPass, string time);

	virtual void saveUser();
	virtual void createUser(string fileID);
};
#endif