#include "Uc.h"

using namespace std;

void Uc::get_classes(string uccode)
{
    Read read;
    vector<classes_per_uc> tmp1 = read.read_classes_per_uc();

    cout << "---\nAll Classes that have the UC " << uccode << ":" << endl << endl;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).UcCode == uccode)
        {
            cout << tmp1.at(i).ClassCode << endl;
        }
    }
}

void Uc::get_students(string uccode, int order)
{
    Read read;
    vector<students_classes> tmp1 = read.read_students_classes();

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