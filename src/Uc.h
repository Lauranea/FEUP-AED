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
    private:
        Scheduler &s; 
    public:
        Uc(Scheduler &s);
        void get_classes(string uccode);
        void get_students(string uccode);

};

#endif
