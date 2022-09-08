#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#ifndef Remove_H
#define Remove_H
using namespace std;
class Remove
{
private:
	int id;
	char ch;
	string filename = "Products.txt";

public:
	void _remove();
};
#endif