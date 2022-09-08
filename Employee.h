#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#ifndef Employee_H
#define Employee_H
using namespace std;

class Employee
{
private:
	int id;
	string name;
	string section;
	int age;

public:
	void employee();
};
#endif