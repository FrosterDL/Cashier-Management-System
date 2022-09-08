#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "mainfunction.h"
#include "Cloths.h"
#include "Invoice.h"
#ifndef Male_H
#define Male_H
using namespace std;

class Male : public Cloths
{
private:
	friend class Add;

public:
	static int male_count;
	int male_price;
	static float total_male_amount;
	Male()
	{
		male_count += 1;
		cout << "	Enter Male Dress ID, Name and Price.\n";
		cout << "\t Male Dress ID: ";
		cin >> dressid;
		cout << "\t Male Dress Name: ";
		cin >> dressname;
		cout << "\t Male Dress Price: ";
		cin >> price;
		male_price = price;
		total_male_amount += male_price;
		system("cls");

		/// Building a file entry combining all infos
		string maleProduct, strDressId, strPrice, dressType = "Male";
		ostringstream ostrDressId, ostrPrice;

		ostrDressId << dressid;
		strDressId = ostrDressId.str();

		ostrPrice << price;
		strPrice = ostrPrice.str();

		maleProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

		/// Writing to file
		fstream productFile;
		productFile.open("Products.txt", ios::app);

		if (!productFile)
			cout << "File not Created!";
		else
		{
			productFile << maleProduct;
			productFile.close();
		}

		/// Going back to main menu after successful inserting male product
		mainMenu();
	}
};

int Male ::male_count = 0;
float Male ::total_male_amount = 0;
#endif