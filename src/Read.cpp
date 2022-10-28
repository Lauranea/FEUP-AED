/**
 * @file Read.h
 * Funções para ler ficheiros
 */

#include "Read.h"

#define RESET "\033[0m"

/**
 * @brief
 * abre o ficheiro classes_per_uc, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes_per_uc> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */
vector<classes_per_uc> Read::read_classes_per_uc()
{
    vector<classes_per_uc> v;
    ifstream fi;
    fi.open("../classes_per_uc.csv");
    if (!fi.is_open())
    {
        return v;
    }

    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_uc p;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << "'" << a.UcCode << "' '" << a.ClassCode << "'" << endl;
    // }

    fi.close();
    return v;
}

/**
 * @brief
 * abre o ficheiro classes, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */
vector<classes> Read::read_classes()
{
    vector<classes> v;
    ifstream fi;
    fi.open("../classes.csv");
    if (!fi.is_open())
    {
        return v;
    }

    string buffer;
    getline(fi, buffer);
    while (getline(fi, buffer))
    {
        stringstream line(buffer);
        string buf;
        classes p;
        getline(line, buf, ',');
        p.ClassCode = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, ',');
        p.Weekday = buf;
        getline(line, buf, ',');
        p.StartHour = buf;
        getline(line, buf, ',');
        p.Duration = buf;
        getline(line, buf, '\r');
        p.Type = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << a.ClassCode << " " << a.UcCode << " " << a.Weekday << " " << a.StartHour << " " << a.Duration << " "
    //     << a.Type << endl;
    // }

    fi.close();
    return v;
}

/**
 * @brief
 * abre o ficheiro students_classes, verifica se não está aberto(se existe), e cria uma vetor com a informação
 * Complexidade: n
 * @return vector<students_classes> vector<classes> devolve um vetor com a informação, se nao existir ficheiro devolve
 * um vetor vazio
 */
vector<students_classes> Read::read_students_classes()
{
    vector<students_classes> v;
    ifstream fi;
    fi.open("../students_classes.csv");
    if (!fi.is_open())
    {
        return v;
    }

    string buffer;
    getline(fi, buffer, '\n');
    while (getline(fi, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        students_classes p;
        getline(line, buf, ',');
        p.StudentCode = buf;
        getline(line, buf, ',');
        p.StudentName = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    // for (auto a : v)
    // {
    //     cout << "'" << a.StudentCode << "' '" << a.StudentName << "' '" << a.UcCode << "' '" << a.ClassCode << "'" <<
    //     endl;
    // }

    fi.close();
    return v;
}
