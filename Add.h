#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "Cloths.h"
#ifndef Add_H
#define Add_H
using namespace std;

class Add : public Cloths
{
private:
	char option;

public:
	Add() {}
	void add();
};

#endif