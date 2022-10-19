#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <set>
#include "Read.h"
#include <algorithm>
#include "Sort.h"
#include "Write.h"

using namespace std;

class Student
{
    public:
        vector<pair<string, vector<string>>> getucsclasses(vector<string>& classes);
        void get_schedule(string studentcode);
        void remove_class(string studentcode, string classcode);
        void remove_uc(string studentcode, string classcode);
        void add_to(string studentcode, string uccode, string classcode);
        void ocupation(bool alpha);
        bool change_uc(string studentcode, string uccodeold, string uccodenew, string classcodenew);
        bool change_oneclass(string studentcode, string uccodeold, string classcodenew);
        bool change_allclass(string studentcode, string classcodenew);
        bool validclass(string classer, string uc, vector<pair<string, vector<string>>> classes);
        bool validuc(string uc, vector<pair<string, vector<string>>> ucs);
        bool mytoupper(string& word);
        vector<string> getucs(string studentcode);
        bool validclass2(string classer, vector<string> classes);
};

#endif