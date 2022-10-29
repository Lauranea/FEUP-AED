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
    vector<pair<string, vector<string>>> getucsclasses(vector<string> &classes);
    vector<string> getucs(string studentcode);
    void get_schedule(string studentcode);
    void ocupation(bool alpha);
    bool change_oneclass(string studentcode, string uccodeold, string classcodenew);
    bool change_allclass(string studentcode, string classcodenew);
    bool validclass(string classer, string uc, vector<pair<string, vector<string>>> classes);
    bool validuc(string uc, vector<pair<string, vector<string>>> ucs);
    bool mytoupper(string &word);
    bool validclass2(string classer, vector<string> classes);
    bool validchangehorario(string student, string classbegone, string classbenow);
    bool validaddhorario(string student, string newclass);
};

#endif