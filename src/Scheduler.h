/**
 * @file Scheduler.h
 * Inicializa todos os vetores
 */

#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "Read.h"
#include "Sort.h"
#include "structs.h"
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

class Scheduler
{
  public:
    void initialize();
    void initialize_all_ucs_classes();
    void initialize_class_horarios();
    void initialize_ocupation();

    bool remove_uc_class(string studentcode, string uccode, string classcode);
    bool is_balanced(string uccode, string classcode);
    bool add_to(string studentcode, string uccode, string classcode);
    bool change_class(string studentcode, string uccode, string classcode, string newclasscode);
    void ocupation();
    bool is_valid_uc_class(string uccode, string classcode);
    bool is_valid_uc(string uccode);
    bool is_valid_class(string classcode);

    vector<vector<string>> schedule(vector<vector<string>> p);

    vector<classes_per_uc> classes_per_uc_v;
    vector<classes> classes_v;
    vector<students_classes> students_classes_v;
    vector<string> all_classes_v;
    vector<pair<string, vector<string>>> ucs_classes_v;
    vector<pair<pair<string, string>, pair<string, vector<float>>>> class_horarios_v;
    map<string, vector<pair<string, int>>> ocupation_v;
};

#endif