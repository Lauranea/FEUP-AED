#include "Sort.h"

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.first < s2.first;
}

bool sortNumerically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.second < s2.second;
}

bool sortCrescenteUc(pair<string, pair<string, int>> s1, pair<string, pair<string, int>> s2)
{
    if (s1.first == s2.first)
    {
        return s1.second.first < s2.second.first;
    }
    return s1.first < s2.first;
}

bool sortDecrescenteUc(pair<string, pair<string, int>> s1, pair<string, pair<string, int>> s2)
{
    if (s1.first == s2.first)
    {
        return s1.second.first < s2.second.first;
    }
    return s1.first > s2.first;
}
