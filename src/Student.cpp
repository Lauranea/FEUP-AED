#include "Student.h"


vector<string> byDay(vector<vector<string>> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        
    }
}

void Student::get_schedule(string classcode)
{
    Read read;
    vector<classes> tmp = read.read_classes();
    cout << "---\nSchedule from class " << classcode << ":" << endl << endl;
    vector<vector<string>> p;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp.at(i).ClassCode == classcode)
        {
            p.push_back({tmp.at(i).UcCode, tmp.at(i).Weekday, tmp.at(i).StartHour, tmp.at(i).Duration, tmp.at(i).Type});
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << "              | Monday    | Tuesday   | Wednesday | Thursday  | Friday   |" << endl;
        cout << "--------------|-----------|-----------|-----------|-----------|----------|" << endl;
        cout << " 08:00 - 08:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 08:30 - 09:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 09:00 - 09:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 09:30 - 10:00 |" << endl;
        cout << "--------------|" << endl;
        cout << " 10:00 - 10:30 |" << endl;
        cout << "--------------|" << endl;
        cout << " 10:30 - 11:00 |" << endl;
        cout << "--------------|" << endl;
        cout << " 11:00 - 11:30 |" << endl;
        cout << "--------------|" << endl;
        cout << " 11:30 - 12:00 |" << endl;
        cout << "--------------|" << endl;
        cout << " 12:00 - 12:30 |" << endl;
        cout << "--------------|" << endl;
        cout << " 12:30 - 13:00 |" << endl;
        cout << "--------------|" << endl;
        cout << " 13:00 - 8:30 |" << endl;
        cout << "--------------|" << endl;
        cout << " 08:30 - 9:00 |" << endl;
        cout << "--------------|" << endl;
        

    }
}