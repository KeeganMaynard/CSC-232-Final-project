//branch version of bearbank
#include <iostream>
#include "BankOfficials.h"
using namespace std;

int main()
{
	//cout << "Initial test statement" << endl;
	BankOfficials <string> employeeList;
	employeeList.hireEmployee("Keegan");
	employeeList.loginIn("Keegan");
	employeeList.hireEmployee("Nathan");
	employeeList.loginIn("Nathan");
	//employeeList.fireEmployee("Keegan");  //delete from root works
	employeeList.fireEmployee("Nathan");
	//employeeList.loginIn("Nathan");		//will break the program, need invalid input handler in function
}