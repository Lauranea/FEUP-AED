/**
 * @file Write.h
 * {COMPLETAR}
 */

#ifndef _WRITE_H_
#define _WRITE_H_

#include "Scheduler.h"
#include "structs.h"
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Write
{
  private:
    Scheduler &s;

  public:
    Write(Scheduler &s);
    bool change_uc(string studentcode, string uccodeold, string uccodenew, string classcodenew);
    bool change_oneclass(string studentcode, string uccodeold, string classcodenew);
    bool change_allclass(string studentcode, string classcodenew);
    vector<string> finduc(string studentcode);
    bool findcodename(string studentcode, string &studentcode2);
    bool add_to2(string studentcode, string studentname, string uc, string stuclass);
    vector<string> getucs(string studentcode);
};

#endif
