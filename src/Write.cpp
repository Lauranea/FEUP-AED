/**
 * @file Write.cpp
 * Funções para reescrever ficheiros
 */

#include "Write.h"
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"

/**
 * @brief 
 * Construtor de new Write:: Write object
 * 
 * @param new_s referência do scheduler
 */
Write::Write(Scheduler &new_s) : s(new_s)
{
}

bool Write::write()
{
    ofstream fo;
    fo.open("../students_classeso.csv");
    if (!fo.is_open())
    {
        cout << "\nCould not open file" << endl;
        return false;
    }
    fo << "StudentCode,StudentName,UcCode,ClassCode\r\n";

    for (int i = 0; i < s.students_classes_v.size(); i++)
    {
        fo << s.students_classes_v[i].StudentCode << "," << s.students_classes_v[i].StudentName << "," << s.students_classes_v[i].UcCode << "," << s.students_classes_v[i].ClassCode << "\r\n";
    }

    fo.close();

    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return true;
}