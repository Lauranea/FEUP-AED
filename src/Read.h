/**
 * @file Read.h 
 * Funções para ler ficheiros
 */

#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <list>


#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "structs.h"

using namespace std;


class Read
{
    public:
        vector<classes_per_uc> read_classes_per_uc();
        vector<classes> read_classes();
        vector<students_classes> read_students_classes();
};

#endif
