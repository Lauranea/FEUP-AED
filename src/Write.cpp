#include "Write.h"
#include "Read.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

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


bool Write::is_balanced(string uccode, string classcode)
{
    Read read;
    vector<pair<string, vector<pair<string, int>>>> p = read.ocupation();
    
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
        if (stu1 != studentcode && stu2 != studentcode)
        {
            fo << buffer;
        }
        else
        {
            if(rt == false)
            {
                string added = stu1 + "," + stu2 + "," + uccode + "," + classcode;
                fo << added << endl;
            }
            string added = stu1 + "," + stu2 + "," + uccode + "," + classcode;
            fo << buffer;
            rt = true;
        }
        getline(line, buf, '\r');
    }
    if(rt == false)
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
            if(studentcoder == 1)
            {
                cout << RED << "---\nInvalid Name." << endl << "Please select a new one" << endl;
            }
            else
            {
                cout << RED << "---\nInvalid Code." << endl << "Please select a new one" << endl;
            }
            cin >> studentcode2;
        }
        if(studentcoder == 1)
        {
            fo << studentcode << "," << studentcode2 + "," << uccode << "," << classcode << endl;
        }
        else
        {
            fo << studentcode2 << "," << studentcode + "," << uccode << "," << classcode << endl;
        }
    }

    fi.close();
    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");

    return rt;
}