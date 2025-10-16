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
#include "utils.h"
#include <cctype>

using namespace std;

vector<personType> selectionSortByFirstName(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int alphabeticallyLowestIndex = i;
        
        // Iterate over all entries after i to check if there is a smaller entry
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    sortedEntries[i2].getFirstName(),
                    sortedEntries[alphabeticallyLowestIndex].getFirstName()
                ) 
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical first name comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[alphabeticallyLowestIndex];
        sortedEntries[alphabeticallyLowestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByLastName(const vector<personType>& entries) {

}

vector<personType> selectionSortByaddress(const vector<personType>& entries) {

}

vector<personType> selectionSortByHeight(const vector<personType>& entries) {

}

vector<personType> selectionSortByDOB(const vector<personType>& entries) {

}

vector<personType> selectionSortByGender(const vector<personType>& entries) {

}

vector<personType> selectionSortByAge(const vector<personType>& entries) {

}

vector<personType> selectionSort(const vector<personType>& entries, const int sortKey) {
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