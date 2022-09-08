#include "Header.h"
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
//#include<amp_short_vectors.h>
#include <sstream>
#include <iostream>
//#include "mainfunction.h"

using namespace std;

void Invoice ::display_invoice()
{
	system("color c");
	cout << "**********INVOICE**********" << endl;
	cout << "---------------------------" << endl;
	if (Male ::male_count > 0)
	{
		cout << "Total Male Cloths: " << Male::male_count << endl;
		cout << "Total Male Cloths Amount: " << Male ::total_male_amount << endl;
	}

	if (Female ::female_count > 0)
	{
		cout << "Total Female Cloths: " << Female::female_count << endl;
		cout << "Total Female Cloths Amount: " << Female ::total_female_amount << endl;
	}

	if (Children::children_count > 0)
	{
		cout << "Total Children Cloths: " << Children::children_count << endl;
		cout << "Total Children Cloths Amount: " << Children::total_children_amount << endl
			 << endl;
	}

	cout << "TOTAL AMOUNT: " << (Male::total_male_amount) + (Female::total_female_amount) + (Children::total_children_amount) << "\n\n";

	cout << "Thanks For Your Purchase at FROSTR" << endl;
	cout << "For any Complain contact us at: \n";
	cout << " Mobile # +996 500 122 786 \n";
	cout << "          +92 323 467 6416 \n";
	cout << "Email: F2021105235@umt.edu.pk \n";
	cout << "       F2021105224@umt.edu.pk \n";
	cout << "       F2021105214@umt.edu.pk \n";
	cout << "	    F2021105218@umt.edu.pk \n";
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*"
		 << "\n\n";
}

void Cloths::getinfo()
{
	/// cout<<"Filename: "<<Filename<<endl;
	cout << "Dress Name: " << dressname << endl;
	cout << "Dress ID: " << dressid << endl;
	cout << "Price: " << price << endl;
}

void Add::add()
{
	system("color d");
	cout << "Follow the Instructions." << endl;
	cout << "\t1 Add Male Dress" << endl;
	cout << "\t2 Add Female Dress" << endl;
	cout << "\t3 Add Children Dress" << endl;
	cout << "\t4 Back Main Menu" << endl;

	cout << "\n\tPlease, Choose an Operation: ";
	cin >> option;
	if (!isdigit(option))
	{
		system("cls");
		cout << "Please enter a Number." << endl;
		add();
	}
	system("cls");

	switch (option)
	{
	case '1':
	{
		Male objMale;

		break;
	}
	case '2':
	{
		Female objFemale;

		break;
	}
	case '3':
	{
		Children objChildren;

		break;
	}
	case '4':
	{
		mainMenu();
		break;
	}
	default:

		system("cls");
		cout << "Enter a number." << endl;
		add();
	}
}

/// Search Class

void Search::_search()
{
	system("color e");
	cout << "Please, Enter the Dress ID to Search: ";
	cin >> option;
	/*if(!isdigit(option)){
		system("cls");
		cout<<"Please, enter a number."<<endl;
		_search();
	}*/

	/// Converting integer dress id to string
	string strDressId, dressType;
	ostringstream ostrDressId;

	ostrDressId << option;
	strDressId = ostrDressId.str();

	/// Reading from file
	fstream productFile;
	productFile.open("Products.txt", ios::in);

	/// Flag for found product or not
	ch = 'n';
	bool search_check = false;

	if (!productFile)
	{
		cout << "No Such File!";
	}
	else
	{
		string line, word, srcDressName, srcPrice;

		while (1) // true
		{
			if (productFile.eof())
				break;

			getline(productFile, line);
			istringstream ss(line);
			ss >> word;

			if (strDressId == word)
				ch = 'y';

			if (ch == 'y')
			{
				cout << "Dress Found!" << endl;
				ss >> dressType;
				ss >> srcDressName;
				ss >> srcPrice;
				cout << "Dress ID: " << word << " - Dress Type: " << dressType << " - Dress Name: " << srcDressName << " - Price: " << srcPrice << endl;
				break;
			}
		}

		if (ch == 'n' && search_check == false)
		{
			cout << "No Such Dress Found!" << endl;
		}
	}
	productFile.close();

	mainMenu();
}

/// Remove Class

void Remove::_remove()
{
	system("color a");
	cout << "Please, Enter the Dress ID to Remove: ";
	cin >> id;

	/// Converting integer dress id to string
	string strDressId;
	ostringstream ostrDressId;

	ostrDressId << id;
	strDressId = ostrDressId.str();

	/// Dress found flag
	bool isDressFound = false;

	/// Reading from file
	ifstream productFile;
	productFile.open("Products.txt", ios::in);

	/// Creating new temporary file to store dresses' infos
	ofstream newProductFile;
	newProductFile.open("temp.txt", ofstream::out);

	if (!productFile)
	{
		cout << "No Such File!";
	}
	else
	{
		string line, word, dressType, srcDressName, srcPrice;

		while (1)
		{
			if (productFile.eof())
				break;

			getline(productFile, line);
			istringstream ss(line);
			ss >> word;

			if (strDressId == word)
			{
				cout << "Dress Found to Delete!" << endl;
				ss >> dressType;
				ss >> srcDressName;
				ss >> srcPrice;
				cout << "Dress ID: " << word << " - Dress Type: " << dressType << " - Dress Name: " << srcDressName << " - Price: " << srcPrice << endl;
				isDressFound = true;
			}
			else
			{
				newProductFile << line;
				newProductFile << "\n";
			}
		}

		if (isDressFound != true)
			cout << "Dress Not Found to Delete!" << endl;
	}

	newProductFile.close();
	productFile.close();

	remove("Products.txt");
	rename("temp.txt", "Products.txt");

	mainMenu();
}

/// Employee Class

void Employee::employee()
{
	system("color d");
	cout << "Please, Follow the Instructions." << endl;
	cout << "\t1 Insert Employee" << endl;
	cout << "\t2 Search Employee" << endl;
	cout << "\n\tPlease, Choose an Operation: ";

	int employeeOption;
	cin >> employeeOption;
	system("cls");

	switch (employeeOption)
	{
	case 1:
	{
		cout << "Please, Enter Employee's Information." << endl;
		cout << "\tEmployee's ID: ";
		cin >> id;
		cout << "\tEmployee's Name: ";
		cin >> name;
		cout << "\tEmployee's Section: ";
		cin >> section;
		cout << "\tEmployee's Age: ";
		cin >> age;
		system("cls");

		/// Building a file entry combining all infos
		string empID, empAge, empInfo;
		ostringstream ostrEmpID, ostrEmpAge;

		ostrEmpID << id;
		empID = ostrEmpID.str();

		ostrEmpAge << age;
		empAge = ostrEmpAge.str();

		empInfo = empID + " " + name + " " + section + " " + empAge + "\n";

		/// Writing to file
		fstream employeeFile;
		employeeFile.open("Employees.txt", ios::app);

		if (!employeeFile)
			cout << "File not Created!";
		else
		{
			employeeFile << empInfo;
			employeeFile.close();
		}

		/// Going back to main menu after successful inserting employee info
		mainMenu();
		break;
	}

	case 2:
	{
		char ch;
		int employeeID;

		cout << "Please, Enter the Employee ID to Search: ";
		cin >> employeeID;

		/// Converting integer employee id to string
		string strEmpId;
		ostringstream ostrEmpId;

		ostrEmpId << employeeID;
		strEmpId = ostrEmpId.str();

		/// Reading from file
		fstream employeeFile;
		employeeFile.open("Employees.txt", ios::in);

		/// Flag for found product or not
		ch = 'n';

		if (!employeeFile)
		{
			cout << "No Such File!";
		}
		else
		{
			string line, word, empName, empSection, empAge;

			while (1)
			{
				if (employeeFile.eof())
					break;

				getline(employeeFile, line);
				istringstream ss(line);
				ss >> word;

				if (strEmpId == word)
					ch = 'y';

				if (ch == 'y')
				{
					cout << "Employee Found!" << endl;
					ss >> empName;
					ss >> empSection;
					ss >> empAge;
					cout << "Emp. ID: " << word << " - Emp. Name: " << empName << " - Emp. Section: " << empSection << " - Emp. Age: " << empAge << endl;
					cout << endl;
					cout << endl;
					break;
				}
			}

			if (ch == 'n')
			{
				cout << "No Such Employee Found!" << endl;
			}
		}
		employeeFile.close();

		mainMenu();
		break;
	}

	default:
		cout << "Please, Enter a Valid Number." << endl;
		employee();
		break;
	}
}

/// Customer Class

void Customer::buy()
{
	system("color d");
	cout << "Please, Follow the Instructions." << endl;
	cout << "\t1 Insert Customer" << endl;
	cout << "\t2 Search Customer" << endl;
	cout << "\n\tPlease, Choose an Operation: ";

	string dummy;
	int customerOption;
	cin >> customerOption;
	system("cls");

	switch (customerOption)
	{
	case 1:
	{
		cout << "Please, Enter Customer's Information." << endl;
		cout << "\tCustomer's Name: ";
		cin >> name;
		// cin>>dummy;
		// name = strcpy(new char[strlen(dummy)+1], dummy);
		cout << "\tDress ID: ";
		cin >> id;
		system("cls");

		/// Building a file entry combining all infos
		string dressID, cusInfo;
		ostringstream ostrDressID;

		ostrDressID << id;
		dressID = ostrDressID.str();

		cusInfo = name + " " + dressID + "\n";

		/// Writing to file
		fstream customerFile;
		customerFile.open("Customers.txt", ios::app);

		if (!customerFile)
			cout << "File not Created!";

		else
		{
			customerFile << cusInfo;
			customerFile.close();
		}

		/// Going back to main menu after successful inserting employee info
		mainMenu();
		break;
	}

	case 2:
	{
		char ch;
		string customerName;

		cout << "Please, Enter the Customer Name to Search: ";
		cin >> customerName;

		/// Reading from file
		fstream customerFile;
		customerFile.open("Customers.txt", ios::in);

		/// Flag for found product or not
		ch = 'n';

		if (!customerFile)
		{
			cout << "No Such File!";
		}
		else
		{
			string line, word, dressID;

			while (1)
			{
				if (customerFile.eof())
					break;

				getline(customerFile, line);
				istringstream ss(line);
				ss >> word;

				if (customerName == word)
					ch = 'y';

				if (ch == 'y')
				{
					cout << "Customer Found!" << endl;
					ss >> dressID;
					cout << "Customer Name: " << word << " - Dress ID: " << dressID << endl;
					break;
				}
			}

			if (ch == 'n')
			{
				cout << "No Such Customer Found!" << endl;
			}
		}
		customerFile.close();

		mainMenu();
		break;
	}

	default:
		cout << "Please, Enter a Valid Number." << endl;
		buy();
		break;
	}
}

void Payment ::payment_interface()
{
	system("color b");
	cout << "	\n \n";
	cout << "	How would you like to pay? \n";
	cout << "	Press 1 for CASH ON DELIVERY \n";
	cout << "	Press 2 for CASH PAYMENT \n";
	cout << "	Press 3 for payment through CREDIT CARD \n";
	cout << "	: ";
	cin >> payment_option;
	if (!isdigit(payment_option))
	{
		system("cls");
		cout << "Please, enter a number." << endl;
		payment_interface();
	}
	switch (payment_option)
	{
	case '1': // ! CASH ON DELIVERY
	{
		cout << "		ENTER YOUR ADDRESS" << endl;

		cout << "COUNTRY: ";
		/// getline(cin,country);
		cin >> country;

		cout << "CITY: ";
		// getline(cin, city);
		cin >> city;

		cout << "SOCIETY: ";
		// getline(cin, society);
		cin >> society;

		cout << "BLOCK: ";
		// getline(cin, block);
		cin >> block;

		cout << "LANE: ";
		// getline(cin, lane);
		cin >> lane;

		cout << "HOUSE#: ";
		// getline(cin, house_number);
		cin >> house_number;

		system("cls");

		cout << "\n\n YOUR ORDER IS CONFRIMED\n";
		cout << "You will recieve your order within 10-15 working days.\n";
		cout << "		FROSTR		" << endl
			 << endl;

		Male::male_count = 0;
		Male::total_male_amount = 0;
		Female ::female_count = 0;
		Female ::total_female_amount = 0;
		Children ::children_count = 0;
		Children::total_children_amount = 0;

		mainMenu();

		break;
	}

	case '2':
	{
		system("cls");

		Male::male_count = 0;
		Male::total_male_amount = 0;
		Female ::female_count = 0;
		Female ::total_female_amount = 0;
		Children ::children_count = 0;
		Children::total_children_amount = 0;

		mainMenu();
		break;
	}

	case '3': // ! CREDIT CARD
	{
		system("cls");
		system("color a");
		cout << "	Enter your CREDIT CARD number: ";
		cin >> card_number;

		cout << "	Valid from: " << endl;

		cout << "DATE: ";
		cin >> credit_card_creation_date;
		if (credit_card_creation_date > 32)
		{
			payment_interface();
		}

		cout << "MONTH: ";
		cin >> credit_card_creation_month;
		if (credit_card_creation_month > 12 | credit_card_creation_month < 1)
		{
			payment_interface();
		}

		cout << "YEAR: ";
		cin >> credit_card_creation_year;
		if (credit_card_creation_year < 2017)
		{
			payment_interface();
		}

		cout << "	Valid Till: " << endl;

		cout << "DATE: ";
		cin >> credit_card_expiry_date;
		if (credit_card_expiry_date > 32)
		{
			payment_interface();
		}

		cout << "MONTH: ";
		cin >> credit_card_expiry_month;
		if (credit_card_expiry_month > 12 | credit_card_expiry_month < 1)
		{
			payment_interface();
		}

		cout << "YEAR: ";
		cin >> credit_card_expiry_year;
		if (credit_card_expiry_year > 2027)
		{
			payment_interface();
		}

		cout << "\n TRANSACTION WAS SUCESSFULLY DONE.\n";

		Male::male_count = 0;
		Male::total_male_amount = 0;
		Female ::female_count = 0;
		Female ::total_female_amount = 0;
		Children ::children_count = 0;
		Children::total_children_amount = 0;

		mainMenu();
		break;
	}
	default:
	{
		system("cls");
		cout << "Please, enter a valid number." << endl;
		payment_interface();
	}
	}
}

/// Report Generation

void MReportGeneration::report()
{
	totalDress = 0;
	dressIDs.clear();

	/// Reading from file
	fstream productFile;
	productFile.open("Products.txt", ios::in);

	if (!productFile)
	{
		cout << "No Such File!";
	}
	else
	{
		string line, dressID, maleDress;

		while (1)
		{
			if (productFile.eof())
				break;

			getline(productFile, line);
			istringstream ss(line);

			ss >> dressID;
			ss >> maleDress;

			if (maleDress == "Male")
			{
				totalDress++;
				dressIDs.push_back(dressID);
				maleDress = " ";
			}
		}
	}
	productFile.close();

	cout << "Total Male Dress: " << totalDress << endl;

	if (totalDress > 0)
	{
		cout << "Male Dress IDs are: ";

		for (int i = 0; i < dressIDs.size(); i++)
			cout << dressIDs[i] << " ";

		cout << endl
			 << endl;
	}
	else
		cout << endl;
}

void FReportGeneration::report()
{
	totalDress = 0;
	dressIDs.clear();

	/// Reading from file
	fstream productFile;
	productFile.open("Products.txt", ios::in);

	if (!productFile)
	{
		cout << "No Such File!";
	}
	else
	{
		string line, dressID, femaleDress;

		while (1)
		{
			if (productFile.eof())
				break;

			getline(productFile, line);
			istringstream ss(line);

			ss >> dressID;
			ss >> femaleDress;

			if (femaleDress == "Female")
			{
				totalDress++;
				dressIDs.push_back(dressID);
				femaleDress = " ";
			}
		}
	}
	productFile.close();

	cout << "Total Female Dress: " << totalDress << endl;

	if (totalDress > 0)
	{
		cout << "Female Dress IDs are: ";

		for (int i = 0; i < dressIDs.size(); i++)
			cout << dressIDs[i] << " ";

		cout << endl
			 << endl;
	}
	else
		cout << endl;
}

void CReportGeneration::report()
{
	totalDress = 0;
	dressIDs.clear();

	/// Reading from file
	fstream productFile;
	productFile.open("Products.txt", ios::in);

	if (!productFile)
	{
		cout << "No Such File!";
	}
	else
	{
		string line, dressID, childrenDress;

		while (1)
		{
			if (productFile.eof())
				break;

			getline(productFile, line);
			istringstream ss(line);

			ss >> dressID;
			ss >> childrenDress;

			if (childrenDress == "Children")
			{
				totalDress++;
				dressIDs.push_back(dressID);
				childrenDress = " ";
			}
		}
	}
	productFile.close();

	cout << "Total Children Dress: " << totalDress << endl;

	if (totalDress > 0)
	{
		cout << "Children Dress IDs are: ";

		for (int i = 0; i < dressIDs.size(); i++)
			cout << dressIDs[i] << " ";

		cout << endl
			 << endl;
	}
	else
		cout << endl;

	mainMenu();
}

int main()
{
	mainMenu();
	system("pause");
	return 0;
}