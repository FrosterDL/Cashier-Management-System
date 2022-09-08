#include <iostream>
#include "Cloths.h"
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "mainfunction.h"
#include "Invoice.h"
#ifndef Female_H
#define Female_H
using namespace std;

class Female : public Cloths
{
private:
	friend class Add;

public:
	static int female_count;
	int female_price;
	static float total_female_amount;
	Female()
	{
		female_count += 1;
		cout << "	Enter Female Dress ID, Name and Price.\n";
		cout << "\t Female Dress ID: ";
		cin >> dressid;
		cout << "\t Female Dress Name: ";
		cin >> dressname;
		cout << "\t Female Dress Price: ";
		cin >> price;
		female_price = price;
		total_female_amount += female_price;
		system("cls");

		/// Building a file entry combining all infos
		string femaleProduct, strDressId, strPrice, dressType = "Female";
		ostringstream ostrDressId, ostrPrice;

		ostrDressId << dressid;
		strDressId = ostrDressId.str();

		ostrPrice << price;
		strPrice = ostrPrice.str();

		femaleProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

		/// Writing to file
		fstream productFile;
		productFile.open("Products.txt", ios::app);

		if (!productFile)
			cout << "File not Created!";
		else
		{
			productFile << femaleProduct;
			productFile.close();
		}

		/// Going back to main menu after successful inserting male product
		mainMenu();
	}
};

int Female ::female_count = 0;
float Female ::total_female_amount = 0;
#endif