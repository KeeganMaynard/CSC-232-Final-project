//branch version of bearbank
#include <iostream>
#include <string>
#include "BankOfficials.h"
using namespace std;

int main()
{
	bool run = true;
	/*
	//cout << "Initial test statement" << endl;
	BankOfficials <string> employeeList;
	employeeList.hireEmployee("Keegan");
	employeeList.loginIn("Keegan");
	employeeList.hireEmployee("Nathan");
	employeeList.loginIn("Nathan");
	//employeeList.fireEmployee("Keegan");  //delete from root works
	employeeList.fireEmployee("Nathan");
	//employeeList.loginIn("Nathan");		//will break the program, need invalid input handler in function
	*/

	while (run)
	{
		cout << "Enter a number: ";
		string input = "";
		int option = -1;
		getline(cin, input);

		try   //validate input
		{
			if (input.length() == 1)
			{
				option = stoi(input);
			}
			else
			{
				throw 1;
			}
		}
		catch (...)
		{
			//display statement will be different after full implementation
			cout << "Invalid input entered." << endl;
			continue;
		}

		switch (option)
		{
		case 1:
		{
			cout << "1 was entered as the input" << endl;
			break;
		}

		case 2:
		{
			cout << "2 was entered as the input" << endl;
			break;
		}
		
		case 3:
		{
			cout << "3 was entered as the input" << endl;
			run = false;
			break;
		}

		default:
		{
			cout << "Invalid input" << endl;
			run = false;
			break;
		}
		}
	}
	return 0;
}