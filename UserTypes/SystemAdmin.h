#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H
#include "Users.h"

class SystemAdmin : public Users
{
public:
	SystemAdmin();
	SystemAdmin(string name, string ID, string password, string type, string login);
	SystemAdmin(string name, string ID, string password, string type);

	void resetPassword(string ID, string newPass);
	string showUserID(string accountNum);
	void createOfficial(string fullName, string ID, string password);
	void deleteOfficial(); // need a pointer to official users
	void activeOfficial();
	void inactiveOfficial();

protected:
	void removeUser(string fileID);
};
#endif 
