#ifndef _WRITE_H_
#define _WRITE_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "structs.h"

using namespace std;

class Write
{
    public:
        bool remove_class(string studentcode, string classcode);
        bool remove_uc(string studentcode, string uccode);
        bool add_to(string studentcode, string uccode, string classcode);
        bool is_balanced(string uccode, string classcode);
        bool remove_uc_class(string studentcode, string uccode, string classcode);
        bool change_uc(string studentcode, string uccodeold, string uccodenew, string classcodenew);
        bool change_oneclass(string studentcode, string uccodeold, string classcodenew);
        bool change_allclass(string studentcode, string classcodenew);
        vector<string> finduc(string studentcode);
        bool findcodename(string studentcode, string& studentcode2);
        bool add_to2(string studentcode, string studentname, string uc, string stuclass);
};

#endif
