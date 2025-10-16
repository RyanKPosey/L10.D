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

void selectionSortByFirstName(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t alphabeticallyLowestIndex = i;

        // Iterate over all entries after i to check if there is a smaller entry
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    entries[i2].getFirstName(),
                    entries[alphabeticallyLowestIndex].getFirstName()
                ) 
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical first name comes first
        const personType temp = entries[i];
        entries[i] = entries[alphabeticallyLowestIndex];
        entries[alphabeticallyLowestIndex] = temp;
    }
}

void selectionSortByLastName(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t alphabeticallyLowestIndex = i;

        // Iterate over all entries after i to check if there is a smaller entry
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    entries[i2].getLastName(),
                    entries[alphabeticallyLowestIndex].getLastName()
                )
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical last name comes first
        const personType temp = entries[i];
        entries[i] = entries[alphabeticallyLowestIndex];
        entries[alphabeticallyLowestIndex] = temp;
    }
}

void selectionSortByAddress(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t alphabeticallyLowestIndex = i;

        // Iterate over all entries after i to check if there is a smaller entry
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically(
                    entries[i2].getAddress(),
                    entries[alphabeticallyLowestIndex].getAddress()
                )
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entries so that lower alphabetical address comes first
        const personType temp = entries[i];
        entries[i] = entries[alphabeticallyLowestIndex];
        entries[alphabeticallyLowestIndex] = temp;
    }
}

void selectionSortByHeight(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t smallestIndex = i;

        // Iterate over all entries after i to check if there is a smaller entry
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (entries[i2].getHeight() < entries[smallestIndex].getHeight()) {
                smallestIndex = i2;
            }
        }

        // Switch entries so that shorter person comes first
        const personType temp = entries[i];
        entries[i] = entries[smallestIndex];
        entries[smallestIndex] = temp;
    }
}

void selectionSortByDOB(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t earliestDOBIndex = i;

        // Iterate over all entries after i to check if there is an earlier DOB
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (entries[i2].getDOB() < entries[earliestDOBIndex].getDOB()) {
                earliestDOBIndex = i2;
            }
        }

        // Switch entries so that earlier DOB comes first
        const personType temp = entries[i];
        entries[i] = entries[earliestDOBIndex];
        entries[earliestDOBIndex] = temp;
    }
}

void selectionSortByGender(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t lowestIndex = i;
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            // compare genders case-insensitively
            char g1 = static_cast<char>(std::tolower(static_cast<unsigned char>(entries[i2].getGender())));
            char g2 = static_cast<char>(std::tolower(static_cast<unsigned char>(entries[lowestIndex].getGender())));
            if (g1 < g2) {
                lowestIndex = i2;
            }
        }

        const personType temp = entries[i];
        entries[i] = entries[lowestIndex];
        entries[lowestIndex] = temp;
    }
}

void selectionSortByAge(vector<personType>& entries) {
    for (size_t i = 0; i < entries.size(); i++) {
        size_t youngestIndex = i;

        // Iterate over all entries after i to check if there is a younger entry
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (entries[i2].getAge() < entries[youngestIndex].getAge()) {
                youngestIndex = i2;
            }
        }

        // Switch entries so that younger person comes first
        const personType temp = entries[i];
        entries[i] = entries[youngestIndex];
        entries[youngestIndex] = temp;
    }
}

void selectionSortByLastNameThenFirstName(vector<personType>& entries) {
    for(size_t i = 0; i < entries.size(); i++) {
        size_t alphabeticallyLowestIndex = i;
        
        // Find alphabetically lowest index
        for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
            if (
                checkIfSmallerAlphabetically( // i2 smaller by last name
                    entries[i2].getLastName(),
                    entries[alphabeticallyLowestIndex].getLastName()
                ) ||
                (
                    !checkIfSmallerAlphabetically( // current lowest index not smaller by last name
                        entries[alphabeticallyLowestIndex].getLastName(),
                        entries[i2].getLastName()
                    ) &&
                    checkIfSmallerAlphabetically( // i2 smaller by first name
                        entries[i2].getFirstName(),
                        entries[alphabeticallyLowestIndex].getFirstName()
                    )
                )
            ) {
                alphabeticallyLowestIndex = i2;
            }
        }

        // Switch entry at current index with entry at index of next lowest alphabetical score
        personType temp = entries[i];
        entries[i] = entries[alphabeticallyLowestIndex];
        entries[alphabeticallyLowestIndex] = temp;
    }
}


void selectionSort(vector<personType>& entries, const char sortKey) {
    switch (sortKey) {
        case 'a':
            selectionSortByFirstName(entries);
            break;
        case 'b':
            selectionSortByLastName(entries);
            break;
        case 'c':
            selectionSortByAddress(entries);
            break;
        case 'd':
            selectionSortByHeight(entries);
            break;
        case 'e':
            selectionSortByDOB(entries);
            break;
        case 'f':
            selectionSortByGender(entries);
            break;
        case 'g':
            selectionSortByAge(entries);
            break;
        case 'h': // Stretch 5 (Last Name, then First Name)
            selectionSortByLastNameThenFirstName(entries);
            break;
        default:
            return; // No sorting if key is invalid
    }
}