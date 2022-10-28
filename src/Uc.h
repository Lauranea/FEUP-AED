/**
 * @file Uc.h
 * Funções que usam como base uma UC
 */

#ifndef _UC_H_
#define _UC_H_

#include "Scheduler.h"
#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Uc
{
  private:
    Scheduler &s;

  public:
    Uc(Scheduler &s);
    void get_classes(string uccode);
    void get_students(string uccode);
};

#endif
