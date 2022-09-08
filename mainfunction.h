#include "Add.h"
#include "Search.h"
#include "Remove.h"
#include "Employee.h"
#include "Customer.h"
#include "Invoice.h"
/*#include "Male.h"
#include "Female.h"
#include "Children.h"*/
#include "ReportGeneration.h"
#include "MReportGeneration.h"
#include "FReportGeneration.h"
#include "CReportGeneration.h"
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
//#include<amp_short_vectors.h>
#include <sstream>
#include <iostream>
#include <fstream>
#ifndef mainfunction_H
#define mainfunction_H
using namespace std;

void mainMenu()
{
	system("color b");
	cout << "********** FROSTR **********" << endl;
	cout << "\t1 Add Dress" << endl;
	cout << "\t2 Search Dress" << endl;
	cout << "\t3 Remove Dress" << endl;
	cout << "\t4 Invoice" << endl;
	cout << "\t5 Employees' Info" << endl;
	cout << "\t6 Customers' Info" << endl;
	cout << "\t7 Generate Report" << endl;
	cout << "\t8 Exit" << endl;

	cout << "\n\tPlease, Choose an Operation: ";

	char operation;
	cin >> operation;

	if (!isdigit(operation)) // ! putting check for data integrity
	{
		system("cls");

		cout << "Please enter a digit." << endl;

		mainMenu();
	}
	system("cls");

	// ? string employee_login_password="";
	// ? string customer_login_password = "";

	switch (operation)
	{
	case '1':
	{
		Add objAdd;
		objAdd.add();
		break;
	}

	case '2':
	{
		Search objSearch;
		objSearch._search();
		break;
	}

	case '3':
	{
		Remove objRemove;
		objRemove._remove();
		break;
	}

	case '4':
	{
		Invoice objInvoice;
		objInvoice.display_invoice();

		Payment objPayment;
		objPayment.payment_interface();
		break;
	}

	/*case '5':
	{
		string employee_login_password = "";

		cout << "Enter Password: ";
		cin >> employee_login_password;

		Employee objEmployee;
		objEmployee.employee();
		break;
	}*/
	case '5':
	{
		string employee_login_password = "";

		unsigned int wrong_employee_password_count = 0;

	return_wrong_employee_login_password:

		cout << "Enter Password: ";
		cin >> employee_login_password;

		fstream PasswordFile;

		PasswordFile.open("Password.txt", ios::in);

		// FLAG FOR FOUND PASSWORD
		bool password_check = false;
		char password_ch = 'n';

		if (!PasswordFile.is_open())
		{
			cout << "ERROR: NO SUCH FILE FOUND" << endl;
		}
		else
		{

			string line, word;
			while (1)
			{
				if (PasswordFile.eof())
				{
					break;
				}
				getline(PasswordFile, line);
				istringstream ss(line);

				ss >> word;

				if (employee_login_password == word)
				{
					password_check = true;
					password_ch = 'y';
				}
				if (password_check == true || password_ch == 'y')
				{
					system("cls");

					Employee objEmployee;
					objEmployee.employee();
					PasswordFile.close();
					break;
				}
			}

			if (password_check == false || password_ch == 'n')
			{
				system("cls");
				wrong_employee_password_count += 1;

				if (wrong_employee_password_count >= 3)
				{
					cout << "Forget Password?" << endl;

					char forget_password_input;

				return_wrong_pet_name_employee:

					cout << "Press 'X' to login from other method.\n";
					cout << "Press 'Z' to try again.\n";

					cin >> forget_password_input;
					system("cls");

					switch (forget_password_input)
					{

					case 'X':
					{
						cout << "Enter your favourite pet name: ";
						string security_pet_name;
						cin >> security_pet_name;

						fstream forget_password_stream;

						forget_password_stream.open("Security.txt", ios::in);

						if (!forget_password_stream.is_open())
						{
							cout << "ERROR: Could'nt open File.\n";
						}

						else
						{
							string pet_name_check;

							forget_password_stream >> pet_name_check;

							if (pet_name_check == security_pet_name)
							{
								system("cls");
								Employee objEmployee;
								objEmployee.employee();
								forget_password_stream.close();
								break;
							}

							else if (pet_name_check != security_pet_name)
							{
								system("cls");
								goto return_wrong_employee_login_password;
							}
						}
					}
					case 'Z':
					{
						mainMenu();
					}
					default:
					{
						goto return_wrong_pet_name_employee;
					}
					}
				}

				cout << "*****INCORRECT PASSWORD*****" << endl;
				goto return_wrong_employee_login_password;
			}
		}
		// passwordFile.close();

		/*Customer objCustomer;
		objCustomer.buy();
		break;*/
		break;
	}

	case '6':
	{
		string customer_login_password = "";

		unsigned int wrong_customer_password_count = 0;

	return_wrong_customer_login_password:

		cout << "Enter Password: ";
		cin >> customer_login_password;

		fstream passwordFile;

		passwordFile.open("Password.txt", ios::in);

		// FLAG FOR FOUND PASSWORD
		bool password_check = false;
		char password_ch = 'n';

		if (!passwordFile.is_open())
		{
			cout << "ERROR: NO SUCH FILE FOUND" << endl;
		}
		else
		{

			string line, word;
			while (1)
			{
				if (passwordFile.eof())
				{
					break;
				}
				getline(passwordFile, line);
				istringstream ss(line);

				ss >> word;

				if (customer_login_password == word)
				{
					password_check = true;
					password_ch = 'y';
				}
				if (password_check == true || password_ch == 'y')
				{
					system("cls");

					Customer objCustomer;
					objCustomer.buy();
					passwordFile.close();
					break;
				}
			}

			if (password_check == false || password_ch == 'n')
			{
				system("cls");
				wrong_customer_password_count += 1;

				if (wrong_customer_password_count >= 3)
				{
					cout << "Forget Password?" << endl;

					char forget_password_input;

				return_wrong_pet_name_customer:

					cout << "Press 'X' to login from other method.\n";
					cout << "Press 'Z' to try again.\n";

					cin >> forget_password_input;
					system("cls");

					switch (forget_password_input)
					{

					case 'X':
					{
						cout << "Enter your favourite pet name: ";
						string security_pet_name;
						cin >> security_pet_name;

						fstream forget_password_stream;

						forget_password_stream.open("Security.txt", ios::in);

						if (!forget_password_stream.is_open())
						{
							cout << "ERROR: Could'nt open File.\n";
						}

						else
						{
							string pet_name_check;

							forget_password_stream >> pet_name_check;

							if (pet_name_check == security_pet_name)
							{
								system("cls");
								Customer objCustomer;
								objCustomer.buy();
								forget_password_stream.close();
								break;
							}

							else if (pet_name_check != security_pet_name)
							{
								system("cls");
								goto return_wrong_customer_login_password;
							}
						}
					}
					case 'Z':
					{
						mainMenu();
					}
					default:
					{
						goto return_wrong_pet_name_customer;
					}
					}
				}

				cout << "*****INCORRECT PASSWORD*****" << endl;
				goto return_wrong_customer_login_password;
			}
		}
		// passwordFile.close();

		/*Customer objCustomer;
		objCustomer.buy();
		break;*/
		break;
	}

	case '7':
	{
		ReportGeneration *objReportGeneration;

		MReportGeneration objMReportGeneration;
		FReportGeneration objFReportGeneration;
		CReportGeneration objCReportGeneration;

		objReportGeneration = &objMReportGeneration;
		objReportGeneration->report();

		objReportGeneration = &objFReportGeneration;
		objReportGeneration->report();

		objReportGeneration = &objCReportGeneration;
		objReportGeneration->report();

		break;
	}

	case '8':
		exit(0);

	default:
		system("cls");
		cout << "Please, Enter a Valid Number." << endl;
		mainMenu();
		break;
	}
}

#endif