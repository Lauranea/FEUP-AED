#include "Student.h"

void Student::get_schedule(string classcode)
{
    Read read;
    vector<classes> tmp1 = read.read_classes();
    cout << "---\nSchedule from class " << classcode << ":" << endl << endl;
    vector<vector<string>> p;
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1.at(i).ClassCode == classcode)
        {
            
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        
    }
}