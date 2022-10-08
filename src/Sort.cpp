#include "Sort.h"

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.first < s2.first;
}

bool sortNumerically(pair<string, string> s1, pair<string, string> s2)
{
    return s1.second < s2.second;
}