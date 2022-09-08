#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <string.h>
#include <fstream>
#include "ReportGeneration.h"
#ifndef MReportGeneration_H
#define MReportGeneration_H
using namespace std;

class MReportGeneration : public ReportGeneration
{
public:
	void report();
};
#endif