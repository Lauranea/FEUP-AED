#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "structs.h"

using namespace std;


class Scheduler
{
    public:
        void initialize();
        void initialize_all_ucs_classes();
        void initialize_class_horarios();
        vector<vector<string>> schedule(vector<vector<string>> p);
        
        vector<classes_per_uc> classes_per_uc_v;
        vector<classes> classes_v;
        vector<students_classes> students_classes_v;
        vector<string> all_classes_v;
        vector<pair<string, vector<string>>> ucs_classes_v;
        vector<pair<pair<string, string>, pair<string, vector<float>>>> class_horarios_v;
};

#endif