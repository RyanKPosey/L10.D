/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/

#include <iostream>
#include <vector>
#include "selectionSort.h"
#include "personType.h"
#include <cctype>

using namespace std;

vector<personType> selectionSortByFirstName(vector<personType> entries) {
    
}

vector<personType> selectionSortByLastName(vector<personType> entries) {

}

vector<personType> selectionSortByaddress(vector<personType> entries) {
    
}

vector<personType> selectionSortByHeight(vector<personType> entries) {
    
}

vector<personType> selectionSortByDOB(vector<personType> entries) {
    
}

vector<personType> selectionSortByGender(vector<personType> entries) {
    
}

vector<personType> selectionSortByAge(vector<personType> entries) {
    
}

vector<personType> selectionSort(vector<personType> entries, int sortKey) {
    switch (sortKey) {
        case '1':
            return selectionSortByFirstName(entries);
        case '2':
            return selectionSortByLastName(entries);
        case '3':
            return selectionSortByaddress(entries);
        case '4':
            return selectionSortByHeight(entries);
        case '5':
            return selectionSortByDOB(entries);
        case '6':
            return selectionSortByGender(entries);
        case '7':
            return selectionSortByAge(entries);
        default:
            return entries; // No sorting if key is invalid
    }
}