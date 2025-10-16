/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>
#include "personType.h"

using namespace std;

vector<personType> selectionSort(const vector<personType>& entries, const int sortKey);

#endif // SELECTION_SORT_H