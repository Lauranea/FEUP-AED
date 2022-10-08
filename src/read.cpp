#include "Read.h"

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
    getline(fi, buffer);
    while (getline(fi, buffer))
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
    getline(fi, buffer);
    while (getline(fi, buffer))
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