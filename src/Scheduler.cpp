/**
 * @file Scheduler.cpp
 * Inicializa todos os vetores
 */

#include "Scheduler.h"

#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"
#define RED "\033[31m"

void Scheduler::initialize()
{
    Read read;
    classes_per_uc_v = read.read_classes_per_uc();
    classes_v = read.read_classes();
    students_classes_v = read.read_students_classes();

    initialize_all_ucs_classes();
    initialize_class_horarios2();
    initialize_ocupation();
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

/*
void Scheduler::initialize_class_horarios()
{
    for (classes i : classes_v)
    {
        if (i.Type == "T")
        {
            continue;
        }
        float duration = atof(i.Duration.c_str());
        float start = atof(i.StartHour.c_str());
        vector<float> times;
        while (duration > 0)
        {
            times.push_back(start);
            duration -= 0.5;
            start += 0.5;
        }
        class_horarios_v.push_back(pair(pair(i.UcCode, i.ClassCode), pair(i.Weekday, times)));
    }
}
*/

void Scheduler::initialize_class_horarios2()
{
    string lastuc = "no";
    // vector<pair<string, vector<pair<string, pair<string, vector<float>>>>>> class_horarios_v2;
    vector<pair<string, pair<string, vector<float>>>> current;
    for (classes i : classes_v)
    {
        if (i.Type == "T")
        {
            continue;
        }
        if(i.UcCode == lastuc)
        {
            float duration = atof(i.Duration.c_str());
            float start = atof(i.StartHour.c_str());
            vector<float> times;
            while (duration > 0)
            {
                times.push_back(start);
                duration -= 0.5;
                start += 0.5;
            }
            current.push_back(pair(i.ClassCode, pair(i.Weekday, times)));
        }
        else
        {
            class_horarios_v2.push_back(pair(i.UcCode, current));
            lastuc = i.UcCode;
            float duration = atof(i.Duration.c_str());
            float start = atof(i.StartHour.c_str());
            vector<float> times;
            while (duration > 0)
            {
                times.push_back(start);
                duration -= 0.5;
                start += 0.5;
            }
            current.push_back(pair(i.ClassCode, pair(i.Weekday, times)));
        }
    }
}

vector<pair<string, int>> c = {{"8", 0}, {"8.5", 2}, {"9", 4}, {"9.5", 6}, {"10", 8}, {"10.5", 10}, {"11", 12}, {"11.5", 14}, {"12", 16}, {"12.5", 18}, {"13", 20}, {"13.5", 22}, {"14", 24}, {"14.5", 26}, {"15", 28}, {"15.5", 30}, {"16", 32}, {"16.5", 34}, {"17", 36}, {"17.5", 38}, {"18", 40}, {"18.5", 42}, {"19", 44}, {"19.5", 46}};

map<string, int> d = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thursday", 3}, {"Friday", 4}};

vector<vector<string>> Scheduler::schedule(vector<vector<string>> p)
{
    vector<vector<string>> a = {{"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "}};

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
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 1) = " " + p.at(i).at(0) + "  ";
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
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 2) = " " + p.at(i).at(0) + "  ";
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
                    a.at(d[p.at(i).at(1)]).at(c.at(j).second + 3) = " " + p.at(i).at(0) + "  ";
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

void Scheduler::initialize_ocupation()
{
    for (int i = 0; i < classes_per_uc_v.size(); i++)
    {
        ocupation_v[classes_per_uc_v[i].UcCode].push_back({classes_per_uc_v[i].ClassCode, 0});
    }
    for (int i = 0; i < students_classes_v.size(); i++)
    {
        for (int j = 0; j < ocupation_v[students_classes_v[i].UcCode].size(); j++)
        {
            if (ocupation_v[students_classes_v[i].UcCode][j].first == students_classes_v[i].ClassCode)
            {
                ocupation_v[students_classes_v[i].UcCode][j].second++;
            }
        }
    }
}

bool Scheduler::remove_uc_class(string studentcode, string uccode, string classcode)
{
    auto it = remove_if(students_classes_v.begin(), students_classes_v.end(), [uccode, classcode, studentcode](students_classes r) { return (r.UcCode == uccode && r.ClassCode == classcode && (r.StudentCode == studentcode || r.StudentName == studentcode)); });
    if (it != students_classes_v.end())
    {
        students_classes_v.erase(it, students_classes_v.end());
        for (int i = 0; i < ocupation_v[uccode].size(); i++)
        {
            if (ocupation_v[uccode][i].first == classcode)
            {
                ocupation_v[uccode][i].second--;
                break;
            }
        }
        return true;
    }
    return false;
}

bool Scheduler::is_balanced(string uccode, string classcode)
{
    for (auto o : ocupation_v)
    {
        if (o.first == uccode)
        {
            int min = INT_MAX;
            int cur = 0;
            for (int j = 0; j < o.second.size(); j++)
            {
                if (o.second[j].second < min)
                {
                    min = o.second[j].second;
                }
                if (o.second[j].first == classcode)
                {
                    cur = o.second[j].second;
                }
            }
            if (cur + 1 - min >= 4)
            {
                return false;
            }
            break;
        }
    }
    return true;
}

bool Scheduler::add_to(string studentcode, string uccode, string classcode)
{
    if (!is_valid_uc_class(uccode, classcode))
    {
        cout << RED << "\nInvalid UC / Class combination" << RESET << endl;
        return false;
    }
    if (!is_balanced(uccode, classcode))
    {
        cout << RED << "\nClasses would be unbalanced" << RESET << endl;
        return false;
    }

    bool can_add = true;
    bool is_name = false;
    string other_code = "";
    for (int i = 0; i < students_classes_v.size(); i++)
    {
        if (students_classes_v[i].StudentCode == studentcode)
        {
            is_name = false;
            other_code = students_classes_v[i].StudentName;
            if (students_classes_v[i].UcCode == uccode && students_classes_v[i].ClassCode == classcode)
            {
                can_add = false;
            }
        }
        else if (students_classes_v[i].StudentName == studentcode)
        {
            is_name = true;
            other_code = students_classes_v[i].StudentCode;
            if (students_classes_v[i].UcCode == uccode && students_classes_v[i].ClassCode == classcode)
            {
                can_add = false;
            }
        }
    }
    if (can_add)
    {
        if (is_name)
        {
            students_classes_v.push_back({other_code, studentcode, uccode, classcode});
        }
        else
        {
            students_classes_v.push_back({studentcode, other_code, uccode, classcode});
        }

        for (int i = 0; i < ocupation_v[uccode].size(); i++)
        {
            if (ocupation_v[uccode][i].first == classcode)
            {
                ocupation_v[uccode][i].second++;
                break;
            }
        }

        return true;
    }
    return false;
}

bool Scheduler::change_class(string studentcode, string uccode, string classcode, string newclasscode)
{
    if (!is_valid_uc_class(uccode, newclasscode) || !is_balanced(uccode, newclasscode))
    {
        return false;
    }

    for (int i = 0; i < students_classes_v.size(); i++)
    {
        if (students_classes_v[i].UcCode == uccode && (students_classes_v[i].StudentCode == studentcode || students_classes_v[i].StudentName == studentcode))
        {
            students_classes_v[i].ClassCode = newclasscode;
            for (int i = 0; i < ocupation_v[uccode].size(); i++)
            {
                if (ocupation_v[uccode][i].first == classcode)
                {
                    ocupation_v[uccode][i].second--;
                }
                if (ocupation_v[uccode][i].first == newclasscode)
                {
                    ocupation_v[uccode][i].second++;
                }
            }
            return true;
        }
    }
    return false;
}

void Scheduler::ocupation()
{
    for (auto o : ocupation_v)
    {
        sort(o.second.begin(), o.second.end());
        cout << BOLDWHITE << endl << o.first << RESET << endl;
        for (int j = 0; j < o.second.size(); j++)
        {
            cout << o.second[j].first << " - " << o.second[j].second << endl;
        }
    }
}

bool Scheduler::is_valid_uc_class(string uccode, string classcode)
{
    for (int i = 0; i < classes_per_uc_v.size(); i++)
    {
        if (classes_per_uc_v[i].UcCode == uccode && classes_per_uc_v[i].ClassCode == classcode)
        {
            return true;
        }
    }
    return false;
}

bool Scheduler::is_valid_uc(string uccode)
{
    for (int i = 0; i < ucs_classes_v.size(); i++)
    {
        if (ucs_classes_v[i].first == uccode)
        {
            return true;
        }
    }
    return false;
}

bool Scheduler::is_valid_class(string classcode)
{
    for (int i = 0; i < all_classes_v.size(); i++)
    {
        if (all_classes_v[i] == classcode)
        {
            return true;
        }
    }
    return false;
}