#include <iostream>

#include "Class.h"
#include "Scheduler.h"
#include "Student.h"
#include "Uc.h"

#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

int main(int argc, char **argv)
{
    Scheduler s;
    s.initialize();

    string r;
    Student student(s);
    Uc uc(s);
    Class class_(s);

    while (true)
    {
        cout << BOLDWHITE << "\n\n1 - View\n2 - Edit\nq - Quit" << endl << endl;
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
                    cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!student.validuc(code, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid UC Code." << RESET << endl;
                        cin >> code;
                    }
                    uc.get_classes(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "2") // Get Students
            {
                cout << "---\nFrom:\n\n1 - UC\n2 - Class" << endl << endl;
                cin >> r;
                if (r == "1")
                {
                    cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!student.validuc(code, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid UC Code." << RESET << endl;
                        cin >> code;
                    }
                    uc.get_students(code);
                }
                else if (r == "2")
                {
                    cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!student.validclass2(code, s.all_classes_v))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> code;
                    }
                    class_.get_students(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "3") // Get Schedule
            {
                cout << "---\nFrom:\n\n1 - Class\n2 - Student" << endl << endl;
                cin >> r;
                if (r == "1")
                {
                    cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!student.validclass2(code, s.all_classes_v))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> code;
                    }
                    class_.get_schedule(code);
                }
                else if (r == "2")
                {
                    cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                    string code;
                    cin >> code;
                    student.get_schedule(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "4") // Get Ocupation
            {
                s.ocupation();
            }
            else
            {
                cout << RED << "---\nInvalid choice." << RESET << endl;
                continue;
            }
        }
        else if (r == "2") // Edit
        {
            cout << "---\n1 - Remove Student\n2 - Add Student\n3 - Change Student" << endl << endl;
            cin >> r;
            if (r == "1") // Remove student
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                student.remove_uc_class(code);
            }
            else if (r == "2") // Add student
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                cout << "---\nTo UC (ex: L.EIC001):" << endl << endl;
                cin >> r;
                if (!s.is_valid_uc(r))
                {
                    cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                }
                string rr;
                cout << "---\nTo Class (ex: 1LEIC01):" << endl << endl;
                cin >> rr;
                if (!s.is_valid_uc_class(r, rr))
                {
                    cout << RED << "---\nInvalid UC / Class combination." << endl;
                }
                s.add_to(code, r, rr);
            }
            else if (r == "3") // Change Student
            {
                int coru;
                cout << "---\n1 - Change UC\n2 - Change one Class\n3 - Change all Classes" << endl << endl;
                cin >> coru;
                if (!(coru == 1 || coru == 2 || coru == 3))
                {
                    cout << RED << "---\nInvalid Option." << RESET << endl;
                    cin >> coru;
                }
                if (coru == 1)
                {
                    cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                    string code;
                    string olduc;
                    cin >> code;
                    cout << "---\nCurrent UC (ex: L.EIC001):" << endl << endl;
                    cin >> olduc;
                    while (!student.validuc(olduc, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                        cin >> olduc;
                    }
                    string newuc;
                    cout << "---\nDesired UC (ex: L.EIC001):" << endl << endl;
                    cin >> newuc;
                    while (!student.validuc(newuc, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                        cin >> newuc;
                    }
                    string newclass;
                    cout << "---\nDesired Class (ex: 1LEIC01):" << endl << endl;
                    cin >> newclass;
                    while (!student.validclass(newclass, newuc, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> newclass;
                    }
                    if (student.change_uc(code, olduc, newuc, newclass))
                    {
                        cout << GREEN << "---\n" << code << " changed from " << olduc << " to " << newuc << " : " << newclass << RESET << endl;
                        continue;
                    }
                    else
                    {
                        cout << RED << "---\n" << code << " was unable to change from " << olduc << " to " << newuc << " : " << newclass << RESET << endl;
                        continue;
                    }
                }
                else if (coru == 2)
                {
                    cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                    string code;
                    string olduc;
                    cin >> code;
                    cout << "---\nUC (ex: L.EIC001):" << endl << endl;
                    cin >> olduc;
                    while (!student.validuc(olduc, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                        cin >> olduc;
                    }
                    string newclass;
                    cout << "---\nDesired Class (ex: 1LEIC01):" << endl << endl;
                    cin >> newclass;
                    while (!student.validclass(newclass, olduc, s.ucs_classes_v))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> newclass;
                    }
                    if (student.change_oneclass(code, olduc, newclass))
                    {
                        cout << GREEN << "---\n" << code << " changed to " << olduc << " : " << newclass << RESET << endl;
                        continue;
                    }
                    else
                    {
                        cout << RED << "---\n"
                             << code << " was unable to change"
                             << " to " << olduc << " : " << newclass << RESET << endl;
                        continue;
                    }
                }
                else if (coru == 3)
                {
                    cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                    string code;

                    cin >> code;
                    string newclass;
                    cout << "---\nDesired Class (ex: 1LEIC01):" << endl << endl;
                    cin >> newclass;
                    bool queque = true;
                    vector<string> verify1 = student.getucs(code);
                    for (string i : verify1)
                    {
                        cout << i << endl;
                        if (!student.validclass(newclass, i, s.ucs_classes_v))
                        {
                            queque = false;
                        }
                    }
                    while (!queque)
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> newclass;
                        queque = true;
                        for (string i : verify1)
                        {
                            if (!student.validclass(newclass, i, s.ucs_classes_v))
                            {
                                queque = false;
                            }
                        }
                    }
                    if (student.change_allclass(code, newclass))
                    {
                        cout << GREEN << "---\n" << code << " changed all classes to " << newclass << RESET << endl;
                        continue;
                    }
                    else
                    {
                        cout << RED << "---\n" << code << " was unable to change all classes to " << newclass << RESET << endl;
                        continue;
                    }
                }
            }
            else
            {
                cout << RED << "---\nInvalid choice." << RESET << endl;
                continue;
            }
        }
        else if (r == "q") // Quit
        {
            return 0;
        }
        else
        {
            cout << RED << "---\nInvalid choice." << RESET << endl;
            continue;
        }
    }

    return 0;
}