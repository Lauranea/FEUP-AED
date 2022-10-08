#include "Class.h"

using namespace std;

void Class::get_students(string classcode, int order)
{
    cout << "---\nAll Students that have the Class " << classcode << ":" << endl << endl;
    Read read;
    vector<students_classes> tmp1 = read.read_students_classes();
    vector<pair<string, string>> p;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).ClassCode == classcode)
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