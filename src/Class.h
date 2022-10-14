#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <string>
#include <iostream>
#include "Read.h"
#include <algorithm>
#include "Sort.h"

using namespace std;

class Class
{
    public:
        void get_students(string classcode);
        void get_schedule(string classcode);

};

#endif