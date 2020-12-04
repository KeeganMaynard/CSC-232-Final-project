#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include "Users.h"

class UserAccounts : public Users
{
private:
	string memberAddress;
	string memberPhone;
public:
	UserAccounts();
	UserAccounts(string name, string ID, string password, string type, string login, string address, string phone);
	UserAccounts(string name, string ID, string password, string type, string address, string phone);

	string getAddress();
	string getPhone();
	void setAddress(string address);
	void setPhone(string phone);

	void saveUser();
	void createUser(string fileID);
	void history(vector<string> accounts);
	void display();
};
#endif