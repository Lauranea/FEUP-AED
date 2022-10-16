#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Read.h"
#include <algorithm>
#include "Sort.h"
#include "Write.h"

using namespace std;

class Student
{
    public:
        void get_schedule(string studentcode);
        void remove_class(string studentcode, string classcode);
        void remove_uc(string studentcode, string classcode);
        void ocupation(bool alpha);

};

#endif