#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
#include "Data Files/avlTree.h"
#include "Data Files/AccountChart.h"
using namespace std;

struct setInfo		//might change the name later
{
	AVLTree<string> fileFirstName, fileLastName, filePhoneNum, fileAddress, fileUser;
	AccountChart accountChart;
};

class DataController
{
public:
	DataController();

	//static keyword prevents things from being altered/redefined
	static setInfo allCharts;
	//vector of the type of accounts 

	//login functions
	static string validLogin(string ID, string password);
	static bool validUser(string ID);
	static bool availableUser(string ID);

	//system admin functions
	static void addOficial(string password, string ID);
	static void addAdmin(string password, string ID);
	static void createAccount(double monthlyFee, double serviceFee, double penalty, double interestRate, double minBalance);	//choose better names
	static void alterAccount(string type, double monthlyFee, double serviceFee, double penalty, double interestRate, double minBalance);
	static void removeAccount(string type);
	//function to get login information from the ID of the user

	//bank official functions
	static void addMember(); // parameters include a member id and account pointers
	//define the account functions 

	//bank member functions
	static string getAccount(string accountNumber);
	static void alterFirstName(string ID, string pastName, string newName);
	static void alterLastname(string ID, string pastName, string newName);
	static void alterAddress(string ID, string pastLocal, string newLocal);
	static void alterPhone(string ID, string pastPhone, string newPhone);
	static bool displayAccounts(string ID);
	static void addAccount(string ID, string newType);
	//function to get list of accounts from the ID of the user
};

setInfo DataController::allFiles = setInfo();		//initializing the files
#endif