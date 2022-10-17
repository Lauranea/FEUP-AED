#include "Read.h"

#define RESET   "\033[0m"

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

vector<classes_per_uc> Read::read_classes_per_uc()
{
    vector<classes_per_uc> v;
    ifstream fi;
    fi.open("../classes_per_uc.csv");
    if (!fi.is_open())
    {
        return v;
    }
    
    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_uc p;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << "'" << a.UcCode << "' '" << a.ClassCode << "'" << endl;
    // }

    fi.close();
    return v;
}

vector<classes> Read::read_classes()
{
    vector<classes> v;
    ifstream fi;
    fi.open("../classes.csv");
    if (!fi.is_open())
    {
        return v;
    }
    
    string buffer;
    getline(fi, buffer);
    while (getline(fi, buffer))
    {
        stringstream line(buffer);
        string buf;
        classes p;
        getline(line, buf, ',');
        p.ClassCode = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, ',');
        p.Weekday = buf;
        getline(line, buf, ',');
        p.StartHour = buf;
        getline(line, buf, ',');
        p.Duration = buf;
        getline(line, buf, '\r');
        p.Type = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << a.ClassCode << " " << a.UcCode << " " << a.Weekday << " " << a.StartHour << " " << a.Duration << " " << a.Type << endl;
    // }

    fi.close();
    return v;
}

vector<students_classes> Read::read_students_classes()
{
    vector<students_classes> v;
    ifstream fi;
    fi.open("../students_classes.csv");
    if (!fi.is_open())
    {
        return v;
    }
    
    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        students_classes p;
        getline(line, buf, ',');
        p.StudentCode = buf;
        getline(line, buf, ',');
        p.StudentName = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << "'" << a.StudentCode << "' '" << a.StudentName << "' '" << a.UcCode << "' '" << a.ClassCode << "'" << endl;
    // }

    fi.close();
    return v;
}



vector<pair<string, vector<pair<string, int>>>> Read::ocupation()
{
    vector<students_classes> p = read_students_classes();
    vector<pair<string, vector<pair<string, int>>>> q;
    for (int i = 0; i < p.size(); i++)
    {
        bool a = true;
        for (int j = 0; j < q.size(); j++)
        {
            if (p[i].UcCode == q[j].first)
            {
                bool b = true;
                for (int k = 0; k < q[j].second.size(); k++)
                {
                    if (q[j].second[k].first == p[i].ClassCode)
                    {
                        q[j].second[k].second++;
                        b = false;
                    }
                }
                if (b)
                {
                    q[j].second.push_back({p[i].ClassCode, 1});
                }
                a = false;
            }
        }
        if (a)
        {
            q.push_back({p[i].UcCode, {{p[i].ClassCode, 1}}});
        }
        
    }

    // for (int i = 0; i < q.size(); i++)
    // {
    //     cout << "'" << q[i].first.first << "' '" << q[i].first.second << "'  " << q[i].second << endl;
    // }

    return q;
}




vector<vector<string>> Read::b(vector<vector<string>> p)
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