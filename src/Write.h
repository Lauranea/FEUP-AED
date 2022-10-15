#ifndef _WRITE_H_
#define _WRITE_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "aux.h"

using namespace std;

class Write
{
    public:
        bool remove_class(string studentcode, string classcode);
        bool remove_uc(string studentcode, string classcode);
};

#endif
