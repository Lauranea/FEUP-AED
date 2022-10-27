#include "Scheduler.h"
#include "Read.h"

void Scheduler::initialize()
{
    Read read;
    classes_per_uc_v = read.read_classes_per_uc();
    classes_v = read.read_classes();
    students_classes_v = read.read_students_classes();
    
    int current_uc_index = -1;
    string current_uc = "";
    for (int i = 0; i < classes_per_uc_v.size(); i++) // initialize all_classes_v and ucs_classes_v
    {
        if (current_uc != classes_per_uc_v[i].UcCode)
        {
            ucs_classes_v.push_back({classes_per_uc_v[i].UcCode, {classes_per_uc_v[i].ClassCode}});
            current_uc_index++;
            current_uc = classes_per_uc_v[i].UcCode;
        }
        else
        {
            ucs_classes_v[current_uc_index].second.push_back(classes_per_uc_v[i].ClassCode);
        }
        bool add = true;
        for (int j = 0; j < all_classes_v.size(); j++)
        {
            if (classes_per_uc_v[i].ClassCode == all_classes_v[j])
            {
                add = false;
            }
        }
        if (add)
        {
            all_classes_v.push_back(classes_per_uc_v[i].ClassCode);
        }
    }


}