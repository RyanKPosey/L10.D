/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/

#include <iostream>
#include <vector>
#include "selection_sort.h"
#include "personType.h"
#include "utils.h"
#include <cctype>

using namespace std;

bool checkIfSmallerAlphabetically(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str1.size() && i < str2.size(); i++) {
        if (
            static_cast<unsigned int>(tolower(str1[i])) < // smaller
            static_cast<unsigned int>(tolower(str2[i]))
        ) {
            return true; // arg1 is smaller alphabetically
        } else if (
            static_cast<unsigned int>(tolower(str1[i])) > 
            static_cast<unsigned int>(tolower(str2[i])) // smaller
        ) {
            return false; // arg2 is smaller alphabetically
        }

        if (str1.size() > i && str2.size() > i) {
            // continue so program doesn't run unnecessary size checks
            continue;
        }

        if (str1.size() < str2.size()) {
            return 0; // str1 is smaller alphabetically
        }

        if (str1.size() > str2.size()) {
            return 1; // str2 is smaller alphabetically
        }
    }

    return false;
}

void selectionSort(vector<personType>& entries, const char sortKey) {
    switch (sortKey) {
        case 'a': {
            for (size_t i = 0; i < entries.size(); i++) {
                size_t alphabeticallyLowestIndex = i;

                // Iterate over all entries after i to check if there is a smaller entry
                for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
                    if (checkIfSmallerAlphabetically(entries[i2].getFirstName(), entries[alphabeticallyLowestIndex].getFirstName())) {
                        alphabeticallyLowestIndex = i2;
                    }
                }

                // Switch entries so that lower alphabetical first name comes first
                const personType temp = entries[i];
                entries[i] = entries[alphabeticallyLowestIndex];
                entries[alphabeticallyLowestIndex] = temp;
            }
        } break;
        case 'b':
        {
            for (size_t i = 0; i < entries.size(); i++) {
                size_t alphabeticallyLowestIndex = i;

                // Iterate over all entries after i to check if there is a smaller entry
                for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
                    if (checkIfSmallerAlphabetically(entries[i2].getLastName(), entries[alphabeticallyLowestIndex].getLastName())) {
                        alphabeticallyLowestIndex = i2;
                    }
                }

                // Switch entries so that lower alphabetical last name comes first
                const personType temp = entries[i];
                entries[i] = entries[alphabeticallyLowestIndex];
                entries[alphabeticallyLowestIndex] = temp;
            }
        } break;
        case 'c':
        {
            for (size_t i = 0; i < entries.size(); i++) {
                size_t alphabeticallyLowestIndex = i;

                // Iterate over all entries after i to check if there is a smaller entry
                for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
                    if (checkIfSmallerAlphabetically(entries[i2].getAddress(), entries[alphabeticallyLowestIndex].getAddress())) {
                        alphabeticallyLowestIndex = i2;
                    }
                }

                // Switch entries so that lower alphabetical address comes first
                const personType temp = entries[i];
                entries[i] = entries[alphabeticallyLowestIndex];
                entries[alphabeticallyLowestIndex] = temp;
            }
        } break;
        case 'd':
        {
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
        } break;
        case 'e':
        {
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
        } break;
        case 'f':
        {
            for (size_t i = 0; i < entries.size(); i++) {
                size_t lowestIndex = i;

                // Iterate over all entries after i to check if there is a smaller entry (by gender)
                for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
                    char g1 = static_cast<char>(std::tolower(static_cast<unsigned char>(entries[i2].getGender())));
                    char g2 = static_cast<char>(std::tolower(static_cast<unsigned char>(entries[lowestIndex].getGender())));
                    if (g1 < g2) {
                        lowestIndex = i2;
                    }
                }

                // Switch entries so that lower alphabetical gender comes first
                const personType temp = entries[i];
                entries[i] = entries[lowestIndex];
                entries[lowestIndex] = temp;
            }
        } break;
        case 'g':
        {
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
        } break;
        case 'h': // Stretch 5 (Last Name, then First Name)
        {
            for(size_t i = 0; i < entries.size(); i++) {
                size_t alphabeticallyLowestIndex = i;

                // Find alphabetically lowest index (by last name, breaking ties on first name)
                for (size_t i2 = i + 1; i2 < entries.size(); i2++) {
                    if (
                        checkIfSmallerAlphabetically(
                            entries[i2].getLastName(),
                            entries[alphabeticallyLowestIndex].getLastName()
                        ) ||
                        (
                            !checkIfSmallerAlphabetically(
                                entries[alphabeticallyLowestIndex].getLastName(),
                                entries[i2].getLastName()
                            ) &&
                            checkIfSmallerAlphabetically(
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
        } break;
        default:
            return; // No sorting if key is invalid
    }
}