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

void Uc::get_students(string uccode)
{
    Read read;
    vector<students_classes> tmp1 = read.read_students_classes();
    string order;
    cout << "---\nOrder:\n\n1 - Alphabetically\n2 - Numerically" << endl << endl;
    cin >> order;
    cout << "---\nAll Students that have the UC " << uccode << ":" << endl << endl;
    vector<pair<string, string>> p;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).UcCode == uccode)
        {
            p.push_back({tmp1.at(i).StudentName,  tmp1.at(i).StudentCode});
        }
    }

    if (order == "1")
    {
        sort(p.begin(), p.end(), sortAlphabetically);
    }
    else if (order == "2")
    {
        sort(p.begin(), p.end(), sortNumerically);
    }
    else
    {
        cout << "---\nInvalid choice." << endl;
        return;
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << p.at(i).first << " - " << p.at(i).second << endl;
    }
}
