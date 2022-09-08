#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#ifndef Customer_H
#define Customer_H
using namespace std;

class Customer
{
private:
	string name;
	// char *name;
	int id;

public:
	void buy();
	//~Customer(){ delete[] name;}
	/// Destructor
	~Customer() {}
};
#endif