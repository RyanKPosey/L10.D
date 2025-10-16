/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/
#include <iostream>
#include "utils.h"

bool checkIfSmallerAlphabetically(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str1.size(), i < str2.size(); i++) {
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