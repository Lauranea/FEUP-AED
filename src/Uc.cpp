/**
 * @file Uc.cpp
 * Funções que usam como base uma UC
 */

#include "Uc.h"

#define RESET "\033[0m"

using namespace std;

Uc::Uc(Scheduler &new_s) : s(new_s)
{
}

/**
 * @brief
 * vai buscar todas as Classes que tem uma Uc;
 * Complexidade: n
 * @param uccode codigo da uc
 */
void Uc::get_classes(string uccode)
{
    cout << RESET << "---\nAll Classes that have the UC " << uccode << ":" << endl << endl;
    for (int i = 0; i < s.classes_per_uc_v.size(); i++)
    {
        if (s.classes_per_uc_v.at(i).UcCode == uccode)
        {
            cout << s.classes_per_uc_v.at(i).ClassCode << endl;
        }
    }
}

/**
 * @brief
 * cria um vetor de pares com (Nome do aluno, codigo do aluno) de uma UC e ordena o de acordo com o que o utilizador escolhe(1 para ordem alfabética e 2 para ordem numérica);
 * Complexidade: n * m
 * @param uccode numero da uc de qual se quer os alunos
 */
void Uc::get_students(string uccode)
{
    string order;
    cout << "---\nOrder:\n\n1 - Alphabetically\n2 - Numerically" << endl << endl;
    cin >> order;
    cout << RESET << "---\nAll Students that have the UC " << uccode << ":" << endl << endl;
    vector<pair<string, string>> p;
    for (int i = 0; i < s.students_classes_v.size(); i++)
    {
        if (s.students_classes_v.at(i).UcCode == uccode)
        {
            bool a = true;
            for (int j = 0; j < p.size(); j++)
            {
                if (s.students_classes_v.at(i).StudentCode == p.at(j).second)
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                p.push_back({s.students_classes_v.at(i).StudentName, s.students_classes_v.at(i).StudentCode});
            }
        }
    }

    if (order == "1")
    {
        sort(p.begin(), p.end(), sortAlphabetically);
    }
    else if (order == "2")
    {
        sort(p.begin(), p.end(), sortNumerically);
    }
    else
    {
        cout << "---\nInvalid choice." << endl;
        return;
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << RESET << p.at(i).first << " - " << p.at(i).second << endl;
    }
}
