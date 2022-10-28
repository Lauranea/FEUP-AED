/**
 * @file Write.cpp
 * {COMPLETAR}
 */

#include "Write.h"
#include "Read.h"
#include <climits>

#define RESET   "\033[0m"
#define RED     "\033[31m"

Write::Write(Scheduler &new_s) : s(new_s) {} 

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
    fo << buffer << "\n";
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
            fo << buffer << "\n";
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
    fo << buffer << "\n";
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
            fo << buffer << "\n";
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

bool Write::remove_uc_class(string studentcode, string uccode, string classcode)
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
    fo << buffer << "\n";
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        string bug;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        getline(line, bug, '\r');
        if ((stu1 != studentcode && stu2 != studentcode) || buf != uccode || bug != classcode)
        {
            fo << buffer << "\n";
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

bool Write::is_balanced(string uccode, string classcode)
{
    vector<pair<string, vector<pair<string, int>>>> p = s.ocupation_v;
    
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].first == uccode)
        {
            int min = INT_MAX;
            int cur = 0;
            for (int j = 0; j < p[i].second.size(); j++)
            {
                if (p[i].second[j].second < min)
                {
                    min = p[i].second[j].second;
                }
                if (p[i].second[j].first == classcode)
                {
                    cur = p[i].second[j].second;
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

bool validcode(string code)
{
    if(code.size() != 9)
    {
        return false;
    }
    for(char i : code)
    {
        if((i >= 65 && i <= 90)||(i <= 122 && i >= 97))
        {
        return false;
        }
    }
    return true;
}

bool validname(string name)
{
    for(char i : name)
    {
        if((i <= 65 || i >= 122)||(i > 97 && i < 90))
        {
        return false;
        }
    }
    return true;
}

bool Write::add_to(string studentcode, string uccode, string classcode)
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
    fo << buffer << "\n";
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        string stu1;
        string stu2;
        getline(line, stu1, ',');
        getline(line, stu2, ',');
        getline(line, buf, ',');
        if (stu1 != studentcode && stu2 != studentcode)
        {
            fo << buffer << "\n";
        }
        else
        {
            if(rt == false)
            {
                string added = stu1 + "," + stu2 + "," + uccode + "," + classcode + "\r";
                fo << added << "\n";
            }
            string added = stu1 + "," + stu2 + "," + uccode + "," + classcode  + "\r";
            fo << buffer << "\n";
            rt = true;
        }
        getline(line, buf, '\r');
    }
    if(!rt)
    {
        string studentcode2;
        bool studentcoder;
        if(studentcode[0] >= 65)
        {
            cout << "---\nStudent Code (ex: 202045037):" << endl << endl;
            studentcoder = 0;
        }
        else
        {
            cout << "---\nStudent Name (ex: Ronaldo):" << endl << endl;
            studentcoder = 1;
        }
        cin >> studentcode2;
        while(studentcode2 == "" || (studentcode2[0] >= 65 && studentcoder == 0) || (studentcode2[0] < 65 && studentcoder == 1) || (validcode(studentcode2) == 0 && studentcoder == 0) || (validname(studentcode2) == 0 && studentcoder == 1))
        {
            if(studentcoder)
            {
                cout << RED << "---\nInvalid Name." << RESET << endl << "Please select a new one" << endl;
            }
            else
            {
                cout << RED << "---\nInvalid Code." << RESET << endl << "Please select a new one" << endl;
            }
            cin >> studentcode2;
        }
        if(studentcoder)
        {
            fo << studentcode << "," << studentcode2 + "," << uccode << "," << classcode << "\n";
        }
        else
        {
            fo << studentcode2 << "," << studentcode + "," << uccode << "," << classcode << "\n";
        }
    }

    fi.close();
    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");

    return rt;
}

bool Write::change_uc(string studentcode, string uccodeold, string uccodenew, string classcodenew)
{
    if(is_balanced(uccodenew, classcodenew))
    {
        add_to(studentcode, uccodenew, classcodenew);
        remove_uc(studentcode, uccodeold);
        return true;
    }
    return false;
}

bool Write::change_oneclass(string studentcode, string uccodeold, string classcodenew)
{
    if(is_balanced(uccodeold, classcodenew))
    {
        remove_uc(studentcode, uccodeold);
        add_to(studentcode, uccodeold, classcodenew);
        return true;
    }
    return false;
}

bool Write::change_allclass(string studentcode, string classcodenew)
{
    string studentcode2;
    bool x = findcodename(studentcode, studentcode2);
    if(x)
    {
        string tmp = studentcode;
        studentcode = studentcode2;
        studentcode2 = tmp;
    }
    if(is_balanced(studentcode, classcodenew))
    {
        vector<string> ok = finduc(studentcode);
        if(ok.size() == 0)
        {
            return 0;
        }
        for(string i : ok)
        {
            remove_uc(studentcode, i);
        }
        for(string i : ok)
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

bool Write::findcodename(string studentcode, string& studentcode2)
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
        else if(stu2 == studentcode)
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
        if(stu1 == studentcode || stu2 == studentcode)
        {
            v.push_back(buf);
        }
    }
    fi.close();

    return v;
}
