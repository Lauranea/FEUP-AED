/**
 * @file Sort.h
 * Funções para ordenar vetores
 */

#ifndef _SORT_H_
#define _SORT_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2);
bool sortNumerically(pair<string, string> s1, pair<string, string> s2);
bool sortCrescenteUc(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);
bool sortDecrescenteUc(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);

#endif