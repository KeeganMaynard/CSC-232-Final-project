#include "DataController.h"
using namespace std;

DataController::DataController()
{
	//default constructor
	;
}

//login functions 
string DataController::validLogin(string ID, string password)
{
	//vector to store values of account information based on the ID entered

	string inputPassword = "", accountPass = "", type = "";	//local variables to store info passed in to function or gathered from file
	//test if anything was added to the vector
	//assign values to the variables, then test if the passed in values match the ones stored in the vector
}

bool DataController::validUser(string ID)
{
	//test if the passed in id already exists in the files and assign it to a boolean variable
	//return that variable
}

bool DataController::availableUser(string ID)
{
	//basically the same as the function above, just tests if the ID is not there instead
}

//system admin functions
void DataController::addOficial(string password, string ID)
{
	//create an entry for official data based on the passed in values then add those to the appropriate file(s)
}

void DataController::addAdmin(string password, string ID)
{
	//basically the same thing as above, just with an admin instead of a bank official
}

