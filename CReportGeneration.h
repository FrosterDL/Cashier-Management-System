#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "ReportGeneration.h"
#ifndef CReportGeneration_H
#define CReportGeneration_H
using namespace std;

class CReportGeneration : public ReportGeneration
{
public:
	void report();
};
#endif