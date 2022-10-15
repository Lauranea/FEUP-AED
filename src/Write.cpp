#include "Write.h"

bool Write::remove_class(string studentcode, string classcode)
{
    ifstream fi;
    ofstream fo;
    fi.open("../students_classes.csv");
    fo.open("../students_classeso.csv");
    if (!fi.is_open() || !fo.is_open())
    {
        cout << "\nCould not open file" << endl;
        return false;
    }

    bool rt = false;
    
    string buffer;
    getline(fi, buffer, '\n');
    fo << buffer;
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        getline(line, buf, '\r');
        if ((stu1 != studentcode && stu2 != studentcode) || buf != classcode)
        {
            fo << buffer;
        }
        else
        {
            rt = true;
        }
    }

    fi.close();
    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");

    return rt;
}

bool Write::remove_uc(string studentcode, string uccode)
{
    ifstream fi;
    ofstream fo;
    fi.open("../students_classes.csv");
    fo.open("../students_classeso.csv");
    if (!fi.is_open() || !fo.is_open())
    {
        cout << "\nCould not open file" << endl;
        return false;
    }

    bool rt = false;
    
    string buffer;
    getline(fi, buffer, '\n');
    fo << buffer;
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        if ((stu1 != studentcode && stu2 != studentcode) || buf != uccode)
        {
            fo << buffer;
        }
        else
        {
            rt = true;
        }
        getline(line, buf, '\r');
    }

    fi.close();
    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");

    return rt;
}