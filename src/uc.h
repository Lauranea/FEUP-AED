#ifndef _UC_H_
#define _UC_H_

#include <vector>
#include <string>
#include <iostream>
#include "read.h"
#include <algorithm>

using namespace std;

class uc
{
    public:
        void get_classes(string uccode);
        void get_students(string uccode, int order);

};

#endif