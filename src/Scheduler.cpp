#include "Scheduler.h"
#include "Read.h"

void Scheduler::initialize()
{
    Read read;
    classes_per_uc_v = read.read_classes_per_uc();
    classes_v = read.read_classes();
    students_classes_v = read.read_students_classes();

    initialize_all_ucs_classes();
}

void Scheduler::initialize_all_ucs_classes()
{
    int current_uc_index = -1;
    string current_uc = "";
    for (int i = 0; i < classes_per_uc_v.size(); i++)
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

vector<pair<string, int>> c =
{
    {"8", 0},
    {"8.5", 2},
    {"9", 4},
    {"9.5", 6},
    {"10", 8},
    {"10.5", 10},
    {"11", 12},
    {"11.5", 14},
    {"12", 16},
    {"12.5", 18},
    {"13", 20},
    {"13.5", 22},
    {"14", 24},
    {"14.5", 26},
    {"15", 28},
    {"15.5", 30},
    {"16", 32},
    {"16.5", 34},
    {"17", 36},
    {"17.5", 38},
    {"18", 40},
    {"18.5", 42},
    {"19", 44},
    {"19.5", 46}
};

map<string, int> d =
{
    {"Monday", 0},
    {"Tuesday", 1},
    {"Wednesday", 2},
    {"Thursday", 3},
    {"Friday", 4}
};

vector<vector<string>> Scheduler::schedule(vector<vector<string>> p)
{
    vector<vector<string>> a = 
    {
        {"           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           "},
        {"           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           "},
        {"           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           "},
        {"           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           "},
        {"           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           ","           "}
    };

    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            if (p.at(i).at(2) == c.at(j).first)
            {
                if (a.at(d[p.at(i).at(1)]).at(c.at(j).second) == "           ")
                {
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second) = "-----------";
                }
                if (p.at(i).at(3) == "1") // duration 1 hour
                {
                    if (p.at(i).at(0).length() == 5)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 1) = " " + p.at(i).at(0) + "     ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 1) = " " + p.at(i).at(0) + "  ";
                    }
                    if (p.at(i).at(4).length() == 1)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 2) = " " + p.at(i).at(4) + "         ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 2) = " " + p.at(i).at(4) + "        ";
                    }
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 4) = "-----------";
                }
                else if (p.at(i).at(3) == "1.5") // duration 1 hour and 30 minutes
                {
                    if (p.at(i).at(0).length() == 5)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 2) = " " + p.at(i).at(0) + "     ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 2) = " " + p.at(i).at(0) + "  ";
                    }
                    if (p.at(i).at(4).length() == 1)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 3) = " " + p.at(i).at(4) + "         ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 3) = " " + p.at(i).at(4) + "        ";
                    }
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 6) = "-----------";
                }
                else // duration 2 hours
                {
                    if (p.at(i).at(0).length() == 5)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 3) = " " + p.at(i).at(0) + "     ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 3) = " " + p.at(i).at(0) + "  ";
                    }
                    if (p.at(i).at(4).length() == 1)
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 4) = " " + p.at(i).at(4) + "         ";
                    }
                    else
                    {
                        a.at(d[p.at(i).at(1)]).at(c.at(j).second + 4) = " " + p.at(i).at(4) + "        ";
                    }
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 8) = "-----------";
                }
            }
        }
        
    }
    return a;
}