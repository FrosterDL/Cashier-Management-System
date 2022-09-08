#include <iostream>
#include "Cloths.h"
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "mainfunction.h"
#include "Invoice.h"
#ifndef Children_H
#define Children_H
using namespace std;
class Children : public Cloths
{
private:
	friend class Add;

public:
	static int children_count;
	float children_price;
	static float total_children_amount;

	Children()
	{
		children_count += 1;
		cout << "		Enter Children Dress ID, Name and Price.\n";
		cout << "\t Children Dress ID: ";
		cin >> dressid;
		cout << "\t Children Dress Name: ";
		cin >> dressname;
		cout << "\t Children Dress Price: ";
		cin >> price;
		children_price = price;
		total_children_amount += children_price;
		system("cls");

		/// Building a file entry combining all infos
		string childrenProduct, strDressId, strPrice, dressType = "Children";
		ostringstream ostrDressId, ostrPrice;

		ostrDressId << dressid;
		strDressId = ostrDressId.str();

		ostrPrice << price;
		strPrice = ostrPrice.str();

		childrenProduct = strDressId + " " + dressType + " " + dressname + " " + strPrice + "\n";

		/// Writing to file
		fstream productFile;
		productFile.open("Products.txt", ios::app);

		if (!productFile)
			cout << "File not Created!";
		else
		{
			productFile << childrenProduct;
			productFile.close();
		}

		/// Going back to main menu after successful inserting male product
		mainMenu();
	}
};

int Children ::children_count = 0;
float Children ::total_children_amount = 0;
#endif