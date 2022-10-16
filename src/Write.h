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
        bool remove_uc(string studentcode, string uccode);
        bool add_to(string studentcode, string uccode, string classcode);
        bool is_not_balanced(string uccode1, string classcode1, string uccode2, string classcode2);
};

#endif
