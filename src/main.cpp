#include <iostream>

#include "Uc.h"
#include "Class.h"

using namespace std;

int main(int argc, char** argv)
{
    string r;

    cout << "1 - View\n2 - Edit" << endl << endl;
    cin >> r;
    if (r == "1")
    {
        cout << "---\n1 - Get Classes\n2 - Get Students" << endl << endl;
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
                if (code.substr(0,5) != "L.EIC")
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
        else
        {
            cout << "---\nInvalid choice." << endl;
            return 0;
        }
    }
    else if (r == "2")
    {

    }
    else
    {
        cout << "---\nInvalid choice." << endl;
    }

    return 0;
}