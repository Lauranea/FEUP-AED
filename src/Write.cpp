/**
 * @file Write.cpp
 * {COMPLETAR}
 */

#include "Write.h"
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"

Write::Write(Scheduler &new_s) : s(new_s)
{
}

bool Write::write()
{
    ofstream fo;
    fo.open("../students_classeso.csv");
    if (!fo.is_open())
    {
        cout << "\nCould not open file" << endl;
        return false;
    }
    fo << "StudentCode,StudentName,UcCode,ClassCode\r\n";

    for (int i = 0; i < s.students_classes_v.size(); i++)
    {
        fo << s.students_classes_v[i].StudentCode << "," << s.students_classes_v[i].StudentName << "," << s.students_classes_v[i].UcCode << "," << s.students_classes_v[i].ClassCode << "\r\n";
    }

    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return true;
}

bool validcode(string code)
{
    if (code.size() != 9)
    {
        return false;
    }
    for (char i : code)
    {
        if ((i >= 65 && i <= 90) || (i <= 122 && i >= 97))
        {
            return false;
        }
    }
    return true;
}

bool validname(string name)
{
    for (char i : name)
    {
        if ((i <= 65 || i >= 122) || (i > 97 && i < 90))
        {
            return false;
        }
    }
    return true;
}

bool Write::change_uc(string studentcode, string uccodeold, string uccodenew, string classcodenew)
{
    if (s.is_balanced(uccodenew, classcodenew))
    {
        // add_to(studentcode, uccodenew, classcodenew);
        // s.remove_uc(studentcode, uccodeold);
        return true;
    }
    return false;
}

bool Write::change_oneclass(string studentcode, string uccodeold, string classcodenew)
{
    if (s.is_balanced(uccodeold, classcodenew))
    {
        // s.remove_uc(studentcode, uccodeold);
        // add_to(studentcode, uccodeold, classcodenew);
        return true;
    }
    return false;
}

bool Write::change_allclass(string studentcode, string classcodenew)
{
    string studentcode2;
    bool x = findcodename(studentcode, studentcode2);
    if (x)
    {
        string tmp = studentcode;
        studentcode = studentcode2;
        studentcode2 = tmp;
    }
    if (s.is_balanced(studentcode, classcodenew))
    {
        vector<string> ok = finduc(studentcode);
        if (ok.size() == 0)
        {
            return 0;
        }
        for (string i : ok)
        {
            // s.remove_uc(studentcode, i);
        }
        for (string i : ok)
        {
            add_to2(studentcode2, studentcode, i, classcodenew);
        }
        return true;
    }
    return false;
}

vector<string> Write::finduc(string studentcode)
{
    vector<string> answer;
    ifstream fi;
    fi.open("../students_classes.csv");
    if (!fi.is_open())
    {
        cout << "\nCould not open file" << endl;
        return answer;
    }

    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        if (stu1 == studentcode || stu2 == studentcode)
        {
            answer.push_back(buf);
        }
        getline(line, buf, '\r');
    }
    return answer;
}

bool Write::findcodename(string studentcode, string &studentcode2)
{
    ifstream fi;
    fi.open("../students_classes.csv");
    if (!fi.is_open())
    {
        cout << "\nCould not open file" << endl;
        return 0;
    }

    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        if (stu1 == studentcode)
        {
            studentcode2 = stu2;
            return 1;
        }
        else if (stu2 == studentcode)
        {
            studentcode2 = stu1;
            return 0;
        }
        getline(line, buf, '\r');
    }
    return 0;
}

bool Write::add_to2(string studentcode, string studentname, string uc, string stuclass)
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
    string buffer;
    while (getline(fi, buffer, '\n'))
    {
        fo << buffer << endl;
    }
    fo << studentcode << "," << studentname << "," << uc << "," << stuclass << endl;
    fi.close();
    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return 1;
}

vector<string> Write::getucs(string studentcode)
{
    vector<string> v;
    ifstream fi;
    fi.open("../students_classes.csv");
    if (!fi.is_open())
    {
        cout << "\nCould not open file" << endl;
        return v;
    }
    string buffer;
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        if (stu1 == studentcode || stu2 == studentcode)
        {
            v.push_back(buf);
        }
    }
    fi.close();

    return v;
}
