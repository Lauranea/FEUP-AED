#include "Sort.h"

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.first < s2.first;
}

bool sortNumerically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.second < s2.second;
}

bool sortCrescenteUc(pair<pair<string, string>, int> s1, pair<pair<string, string>, int> s2)
{
    if (s1.first.first == s2.first.first)
    {
        return s1.first.second < s2.first.second;
    }
    return s1.first.first < s2.first.first;
}

bool sortDecrescenteUc(pair<pair<string, string>, int> s1, pair<pair<string, string>, int> s2)
{
    if (s1.first.first == s2.first.first)
    {
        return s1.first.second < s2.first.second;
    }
    return s1.first.first > s2.first.first;
}