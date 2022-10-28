#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <string>
#include <iostream>
#include "Scheduler.h"
#include <algorithm>
#include "Sort.h"

using namespace std;

class Class
{
    public:
        void get_students(Scheduler &s, string classcode);
        void get_schedule(Scheduler &s, string classcode);

};

#endif