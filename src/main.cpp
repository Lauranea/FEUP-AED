#include <iostream>

#include <uc.h>

using namespace std;

int main(int argc, char** argv)
{
    string r;

    cout << "1 - View\n2 - Edit" << endl << endl;
    cin >> r;
    if (r == "1")
    {
        cout << "---\n1 - UC\n2 - Class" << endl << endl;
        cin >> r;
        if (r == "1")
        {
            uc uc_;
            cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
            string code;
            cin >> code;
            if (code.substr(0,5) != "L.EIC")
            {
                cout << "---\nInvalid UC Code." << endl;
                return 0;
            }
            cout << "---\n1 - Get Classes\n2a - Get Students (Alphabetic order)\n2b - Get Students (Numeric order)" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                uc_.get_classes(code);
            }
            else if (r == "2a")
            {
                uc_.get_students(code, 1);
            }
            else if (r == "2b")
            {
                uc_.get_students(code, 2);
            }
            else
            {
                cout << "---\nInvalid choice." << endl;
                return 0;
            }
        }
        else if (r == "2")
        {
            uc uc_;
            cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
            string code;
            cin >> code;
            if (code.substr(1,4) != "LEIC")
            {
                cout << "---\nInvalid Class Code." << endl;
                return 0;
            }
            cout << "---\n1 - Get Students" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                
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