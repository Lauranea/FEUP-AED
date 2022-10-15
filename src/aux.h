#ifndef _AUX_H_
#define _AUX_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

struct classes_per_uc
{
    string UcCode;
    string ClassCode;
};

struct classes
{
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    string Type;
};

struct students_classes
{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};


#endif