/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/
#include <iostream>
#include "utils.h"

int getLargerStringAlphabetically(const std::string& str1, const std::string& str2) {
    for (size_t i = 0; i < str1.size(), i < str2.size(); i++) {
        if (
            static_cast<unsigned int>(tolower(str1[i])) > // larger
            static_cast<unsigned int>(tolower(str2[i]))
        ) {
            return 0; // arg1 is bigger alphabetically
        } else if (
            static_cast<unsigned int>(tolower(str1[i])) < // smaller
            static_cast<unsigned int>(tolower(str2[i]))
        ) {
            return 1; // arg2 is bigger alphabetically
        }

        if (str1.size() > i && str2.size() > i) {
            // continue so program doesn't run unnecessary size checks
            continue;
        }

        if (str1.size() > str2.size()) {
            return 0; // str1 is bigger alphabetically
        }

        if (str1.size() < str2.size()) {
            return 1; // str2 is bigger alphabetically
        }
    }

    return -1; // strings are the same alphabetically
}