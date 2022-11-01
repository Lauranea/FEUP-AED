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
    bool write();
};

#endif
