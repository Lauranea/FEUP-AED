/**
 * @file Class.h
 * Funções que usam como base uma Class
 */

#ifndef _CLASS_H_
#define _CLASS_H_

#include "Scheduler.h"
#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Class
{
  private:
    Scheduler &s;

  public:
    Class(Scheduler &s);
    void get_students(string classcode);
    void get_schedule(string classcode);
};

#endif