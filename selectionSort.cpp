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
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int alphabeticallyLowestIndex = i;
        
        // Iterate over all entries after i to check if there is a smaller entry
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    sortedEntries[i2].getLastName(),
                    sortedEntries[alphabeticallyLowestIndex].getLastName()
                ) 
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical last name comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[alphabeticallyLowestIndex];
        sortedEntries[alphabeticallyLowestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByAddress(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int alphabeticallyLowestIndex = i;

        // Iterate over all entries after i to check if there is a smaller entry
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    sortedEntries[i2].getAddress(),
                    sortedEntries[alphabeticallyLowestIndex].getAddress()
                )
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical address comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[alphabeticallyLowestIndex];
        sortedEntries[alphabeticallyLowestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByHeight(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int tallestIndex = i;

        // Iterate over all entries after i to check if there is a taller entry
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (sortedEntries[i2].getHeight() > sortedEntries[tallestIndex].getHeight()) {
                tallestIndex = i2;
            }
        }

        // Switch entries so that taller person comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[tallestIndex];
        sortedEntries[tallestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByDOB(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int earliestDOBIndex = i;

        // Iterate over all entries after i to check if there is an earlier DOB
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (sortedEntries[i2].getDOB() < sortedEntries[earliestDOBIndex].getDOB()) {
                earliestDOBIndex = i2;
            }
        }

        // Switch entries so that earlier DOB comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[earliestDOBIndex];
        sortedEntries[earliestDOBIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByGender(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < static_cast<int>(sortedEntries.size()); i++) {
        int lowestIndex = i;
        for (int i2 = i + 1; i2 < static_cast<int>(sortedEntries.size()); i2++) {
            // compare genders case-insensitively
            char g1 = static_cast<char>(std::tolower(static_cast<unsigned char>(sortedEntries[i2].getGender())));
            char g2 = static_cast<char>(std::tolower(static_cast<unsigned char>(sortedEntries[lowestIndex].getGender())));
            if (g1 < g2) {
                lowestIndex = i2;
            }
        }

        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[lowestIndex];
        sortedEntries[lowestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSortByAge(const vector<personType>& entries) {
    vector<personType> sortedEntries = entries;

    for (int i = 0; i < sortedEntries.size(); i++) {
        int youngestIndex = i;

        // Iterate over all entries after i to check if there is a younger entry
        for (int i2 = i + 1; i2 < sortedEntries.size(); i2++) {
            if (sortedEntries[i2].getAge() < sortedEntries[youngestIndex].getAge()) {
                youngestIndex = i2;
            }
        }

        // Switch entries so that younger person comes first
        const personType temp = sortedEntries[i];
        sortedEntries[i] = sortedEntries[youngestIndex];
        sortedEntries[youngestIndex] = temp;
    }

    return sortedEntries;
}

vector<personType> selectionSort(const vector<personType>& entries, const int sortKey) {
    switch (sortKey) {
        case '1':
            return selectionSortByFirstName(entries);
        case '2':
            return selectionSortByLastName(entries);
        case '3':
            return selectionSortByAddress(entries);
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