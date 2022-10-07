#include "uc.h"

using namespace std;

read read_;

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.first < s2.first;
}

bool sortNumerically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.second < s2.second;
}

void uc::get_classes(string uccode)
{
    vector<classes_per_uc> tmp1 = read_.read_classes_per_uc();

    cout << "---\nAll Classes that have the UC " << uccode << ":" << endl << endl;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).UcCode == uccode)
        {
            cout << tmp1.at(i).ClassCode << endl;
        }
    }
}

void uc::get_students(string uccode, int order)
{
    vector<students_classes> tmp1 = read_.read_students_classes();

    cout << "---\nAll Students that have the UC " << uccode << ":" << endl << endl;
    vector<pair<string, string>> p;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).UcCode == uccode)
        {
            p.push_back({tmp1.at(i).StudentName,  tmp1.at(i).StudentCode});
        }
    }

    if (order == 1)
    {
        sort(p.begin(), p.end(), sortAlphabetically);
    }
    else
    {
        sort(p.begin(), p.end(), sortNumerically);
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << p.at(i).first << " - " << p.at(i).second << endl;
    }
}