#include <iostream>

#include "Uc.h"
#include "Class.h"
#include "Student.h"

using namespace std;

int main(int argc, char** argv)
{
    string r;

    cout << "1 - View\n2 - Edit" << endl << endl;
    cin >> r;
    if (r == "1") // View
    {
        cout << "---\n1 - Get Classes\n2 - Get Students\n3 - Get Schedule\n4 - Get ocupation" << endl << endl;
        cin >> r;
        if (r == "1") // Get Classes
        {
            cout << "---\nFrom:\n\n1 - UC" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                Uc uc;
                cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                string code;
                cin >> code;
                if (code.substr(0,5) != "L.EIC")
                {
                    cout << "---\nInvalid UC Code." << endl;
                    return 0;
                }
                uc.get_classes(code);
            }
            else
            {
                cout << "---\nInvalid choice." << endl;
                return 0;
            }
        }
        else if (r == "2") // Get Students
        {
            cout << "---\nFrom:\n\n1 - UC\n2 - Class" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                Uc uc;
                cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                string code;
                cin >> code;
                if (code.substr(0,5) != "L.EIC")
                {
                    cout << "---\nInvalid UC Code." << endl;
                    return 0;
                }
                uc.get_students(code);
            }
            else if (r == "2")
            {
                Class class_;
                cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                string code;
                cin >> code;
                if (code.substr(1,4) != "LEIC")
                {
                    cout << "---\nInvalid UC Code." << endl;
                    return 0;
                }
                class_.get_students(code);
            }
            else
            {
                cout << "---\nInvalid choice." << endl;
                return 0;
            }
        }
        else if (r == "3") // Get Schedule
        {
            cout << "---\nFrom:\n\n1 - Class\n2 - Student" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                Class class_;
                cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                string code;
                cin >> code;
                if (code.substr(1,4) != "LEIC")
                {
                    cout << "---\nInvalid Class Code." << endl;
                    return 0;
                }
                class_.get_schedule(code);
            }
            else if (r == "2")
            {
                Student student;
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                student.get_schedule(code);
            }
            else
            {
                cout << "---\nInvalid choice." << endl;
                return 0;
            }
        }
        else if (r == "4") // Get Ocupation
        {
            Student student;
            student.ocupation(true);
        }
        else
        {
            cout << "---\nInvalid choice." << endl;
            return 0;
        }
    }
    else if (r == "2") // Edit
    {
        cout << "---\n1 - Remove Student\n2 - Add Student\n3 - Change Student" << endl << endl;
        cin >> r;
        if (r == "1") // Remove student
        {
            Student student;
            cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
            string code;
            cin >> code;
            cout << "---\nFrom:\n\n1 - Class\n2 - UC" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                cout << "---\nClass  Code (ex: 1LEIC01):" << endl << endl;
                cin >> r;
                if (r.substr(1,4) != "LEIC")
                {
                    cout << "---\nInvalid Class Code." << endl;
                    return 0;
                }
                student.remove_class(code, r);
            }
            else if (r == "2")
            {
                cout << "---\nUc  Code (ex: L.EIC001):" << endl << endl;
                cin >> r;
                if (r.substr(0,5) != "L.EIC")
                {
                    cout << "---\nInvalid Uc Code." << endl;
                    return 0;
                }
                student.remove_uc(code, r);
            }
            else
            {
                cout << "---\nInvalid choice." << endl;
                return 0;
            }
        }
        else
        {
            cout << "---\nInvalid choice." << endl;
            return 0;
        }
    }
    else
    {
        cout << "---\nInvalid choice." << endl;
        return 0;
    }

    return 0;
}