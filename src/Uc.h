#ifndef _UC_H_
#define _UC_H_

#include <vector>
#include <string>
#include <iostream>
#include "Scheduler.h"
#include <algorithm>
#include "Sort.h"

using namespace std;

class Uc
{
    public:
        void get_classes(Scheduler &s, string uccode);
        void get_students(Scheduler &s, string uccode);

};

#endif
