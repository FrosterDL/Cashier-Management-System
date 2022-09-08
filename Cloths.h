#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
//#include<amp_short_vectors.h>
#include <sstream>
#ifndef Cloths_H
#define Cloths_H
#include <iostream>

using namespace std;

/// Cloths Class - Base Class
class Cloths
{
private:
	string Filename = "Products.txt";

public:
	string dressname;
	int dressid;
	float price;

	void getinfo();
};
#endif
