#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <vector>
//#include <afxtempl.h>
#ifndef ReportGeneration_H
#define ReportGeneration_H
using namespace std;

class ReportGeneration
{
public:
	int totalDress;
	vector<string> dressIDs;

	virtual void report(){};
};
#endif