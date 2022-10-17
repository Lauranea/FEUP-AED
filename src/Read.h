#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "aux.h"

using namespace std;


class Read
{
    public:
        vector<classes_per_uc> read_classes_per_uc();
        vector<classes> read_classes();
        vector<students_classes> read_students_classes();
        vector<vector<string>> b(vector<vector<string>> p);
        vector<pair<string, vector<pair<string, int>>>> ocupation();
};

#endif
