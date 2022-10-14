#include "Student.h"


vector<pair<string, int>> c =
{
    {"8", 0},
    {"8.5", 2},
    {"9", 4},
    {"9.5", 6},
    {"10", 8},
    {"10.5", 10},
    {"11", 12},
    {"11.5", 14},
    {"12", 16},
    {"12.5", 18},
    {"13", 20},
    {"13.5", 22},
    {"14", 24},
    {"14.5", 26},
    {"15", 28},
    {"15.5", 30},
    {"16", 32},
    {"16.5", 34},
    {"17", 36},
    {"17.5", 38},
    {"18", 40},
    {"18.5", 42},
    {"19", 44},
    {"19.5", 46},
    
};

vector<string> b(vector<vector<string>> p, string d)
{
    vector<string> a = 
    {
        "           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------","           ","-----------"
    };

    for (int i = 0; i < p.size(); i++)
    {
        if (p.at(i).at(1) == d)
        {
            for (int j = 0; j < c.size(); j++)
            {
                if (p.at(i).at(2) == c.at(j).first)
                {
                    a.at(c.at(j).second) = " " + p.at(i).at(0) + "  ";
                    if (p.at(i).at(4).length() == 1)
                    {
                        a.at(c.at(j).second + 1) = " " + p.at(i).at(4) + "         ";
                    }
                    else
                    {
                        a.at(c.at(j).second + 1) = " " + p.at(i).at(4) + "        ";
                    }
                }
            }
        }
    }
    return a;
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

    vector<string> Monday = b(p, "Monday");
    vector<string> Tuesday = b(p, "Tuesday");
    vector<string> Wednesday = b(p, "Wednesday");
    vector<string> Thursday = b(p, "Thursday");
    vector<string> Friday = b(p, "Friday");

    cout << "///////////////| Monday    | Tuesday   | Wednesday | Thursday  | Friday   |" << endl;
    cout << "---------------|-----------|-----------|-----------|-----------|----------|" << endl;
    cout << " 08:00 - 08:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(1) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 08:30 - 09:00 |" << Monday.at(2) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(3) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 09:00 - 09:30 |" << Monday.at(4) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(5) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 09:30 - 10:00 |" << Monday.at(6) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 10:00 - 10:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 10:30 - 11:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 11:00 - 11:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 11:30 - 12:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 12:00 - 12:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 12:30 - 13:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 13:00 - 13:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 13:30 - 14:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 14:00 - 14:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 14:30 - 15:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 15:00 - 15:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 15:30 - 16:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 16:00 - 16:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 16:30 - 17:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 17:00 - 17:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 17:30 - 18:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 18:00 - 18:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 18:30 - 19:00 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << " 19:00 - 19:30 |" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;
    cout << "---------------|" << Monday.at(0) << "|" << Tuesday.at(0) << "|" << Wednesday.at(0) << "|" << Thursday.at(0) << "|" << Friday.at(0) << "|" << endl;

    
}