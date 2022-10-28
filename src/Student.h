/**
 * @file Student.h
 * {COMPLETAR}
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <set>
#include "Scheduler.h"
#include <algorithm>
#include "Sort.h"
#include "Write.h"

using namespace std;

class Student
{
    private:
        Scheduler &s;
    public:
        Student(Scheduler &s);
        vector<pair<string, vector<string>>> getucsclasses(vector<string>& classes);
        vector<string> getucs(string studentcode);
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
        bool validclass2(string classer, vector<string> classes);
        bool validchangehorario(string student, string classbegone, string classbenow);
        bool validaddhorario(string student, string newclass);
};

#endif