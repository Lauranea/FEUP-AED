#include "uc.h"

using namespace std;

read read_;

vector<string> uc::getUC(string uccode)
{
    vector<string> v;
    vector<classes_per_uc> tmp1 = read_.read_classes_per_uc();
    vector<classes> tmp2 = read_.read_classes();
    vector<students_classes> tmp3 = read_.read_students_classes();

    // for (int i = 0; i < tmp.size(); i++)
    // {
    //     if (tmp.at(i).first == uccode)
    //     {
    //         v.push_back(tmp.at(i).second);
    //     }
    // }

    // for (auto a : v)
    // {
    //     cout << a << endl;
    // }

    return v;
}