/**
 * @file Student.h
 * {COMPLETAR}
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Scheduler.h"
#include "Sort.h"
#include "Write.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Student
{
  private:
    Scheduler &s;

  public:
    Student(Scheduler &s);
    void get_schedule(string studentcode);
    bool validclass(string classer, string uc, vector<pair<string, vector<string>>> classes);
    bool validuc(string uc, vector<pair<string, vector<string>>> ucs);
    bool validclass2(string classer, vector<string> classes);
};

#endif