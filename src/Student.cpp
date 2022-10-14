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
        cout << "///////////////| Monday    | Tuesday   | Wednesday | Thursday  | Friday   |" << endl;
        cout << "---------------|-----------|-----------|-----------|-----------|----------|" << endl;
        cout << " 08:00 - 08:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 08:30 - 09:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 09:00 - 09:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 09:30 - 10:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 10:00 - 10:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 10:30 - 11:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 11:00 - 11:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 11:30 - 12:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 12:00 - 12:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 12:30 - 13:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 13:00 - 13:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 13:30 - 14:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 14:00 - 14:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 14:30 - 15:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 15:00 - 15:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 15:30 - 16:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 16:00 - 16:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 16:30 - 17:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 17:00 - 17:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 17:30 - 18:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 18:00 - 18:30 |" << endl;
        cout << "---------------|" << endl;
        cout << " 18:30 - 19:00 |" << endl;
        cout << "---------------|" << endl;
        cout << " 19:00 - 19:30 |" << endl;
        cout << "---------------|" << endl;

    }
}