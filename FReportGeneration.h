#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "ReportGeneration.h"
#ifndef FReportGeneration_H
#define FReportGeneration_H
using namespace std;

class FReportGeneration : public ReportGeneration
{
public:
	void report();
};
#endif