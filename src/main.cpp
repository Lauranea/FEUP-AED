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
                cout << "\n---\nUCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < s.students_classes_v.size(); i++)
                {
                    if (s.students_classes_v[i].StudentCode == code || s.students_classes_v[i].StudentName == code)
                    {
                        c[s.students_classes_v[i].UcCode] = s.students_classes_v[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout<< RESET << cc.first << endl;
                }
                string uccode;
                cout << "\n---\nUC Code:" << endl << endl;
                cin >> uccode;

                if (s.remove_uc_class(code, uccode, c[uccode]))
                {
                    cout << RESET << "\nRemoved student " << code << " from UC / Class  " << uccode << " / " << c[uccode] << endl;
                }
                else
                {
                    cout << RED << "\nFailed to remove student " << code << " from UC / Class  " << uccode << " / " << c[uccode] << endl;
                }
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
                    continue;
                }
                cout << "\n---\nClasses:" << endl;
                for (int i = 0; i < s.classes_per_uc_v.size(); i++)
                {
                    if (s.classes_per_uc_v[i].UcCode == r)
                    {
                        cout << RESET << s.classes_per_uc_v[i].ClassCode << endl;
                    }
                }
                string rr;
                cout << "\n---\nTo Class:" << endl << endl;
                cin >> rr;
                if (!s.is_valid_uc_class(r, rr))
                {
                    cout << RED << "---\nInvalid UC / Class combination." << endl;
                    continue;
                }
                if (s.add_to(code, r, rr))
                {
                    cout << RESET << "\nAdded student " << code << " to UC / Class  " << r << " / " << rr << endl;
                }
                else
                {
                    cout << RED << "\nFailed to remove student " << code << " from UC / Class  " << r << " / " << rr << endl;
                }
            }
            else if (r == "3") // Change Student
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                cout << "\n---\nUCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < s.students_classes_v.size(); i++)
                {
                    if (s.students_classes_v[i].StudentCode == code || s.students_classes_v[i].StudentName == code)
                    {
                        c[s.students_classes_v[i].UcCode] = s.students_classes_v[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout<< RESET << cc.first << endl;
                }
                cout << "\n---\nChange Class of UC:" << endl << endl;
                string uccode;
                cin >> uccode;
                if (!s.is_valid_uc(uccode))
                {
                    cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                    continue;
                }
                cout << "\n---\nClasses:" << endl;
                for (int i = 0; i < s.classes_per_uc_v.size(); i++)
                {
                    if (s.classes_per_uc_v[i].UcCode == uccode)
                    {
                        cout << RESET << s.classes_per_uc_v[i].ClassCode << endl;
                    }
                }
                string newclass;
                cout << "---\nTo Class (ex: 1LEIC01):" << endl << endl;
                cin >> newclass;
                if (!s.is_valid_uc_class(uccode, newclass))
                {
                    cout << RED << "---\nInvalid UC / Class Combination." << RESET << endl;
                    continue;
                }
                if (s.change_class(code, uccode, c[uccode],  newclass))
                {
                    cout << GREEN << "---\nUC " << uccode << " changed to Class " << newclass << RESET << endl;
                    continue;
                }
                else
                {
                    cout << RED << "---\nUC " << code << " was unable to change to Class " << newclass << RESET << endl;
                    continue;
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