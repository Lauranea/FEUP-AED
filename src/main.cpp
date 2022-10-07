#include <iostream>

#include <uc.h>

using namespace std;

void number_of_students_per_class(string uccode)
{
    uc uc_;
    uc_.getUC(uccode);
}

int main(int argc, char** argv)
{
    string r;

    cout << "1 - View\n2 - Edit" << endl << endl;
    cin >> r;
    if (r == "1")
    {
        cout << "---\n1 - Number of students per class" << endl << endl;
        cin >> r;
        if (r == "1")
        {
            cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
            cin >> r;
            number_of_students_per_class(r);
        }
    }
    else if (r == "2")
    {

    }
    else
    {
        cout << "Invalid option";
    }

    return 0;
}