/*
    Programmer: Ryan Posey
    Assignment: L10.C
    Purpose: Practice using constructors
    Due date: 10/02/2025
*/

#include <iostream>
#include "personType.h"
#include <cstdint>
#include <iomanip>

using namespace std;

personType::personType( // Full constructor
    string firstName, string lastName, string address, 
    double height, string DOB, char gender, uint16_t age
) {
    name_ = firstName + " " + lastName;
    address_ = address;
    height_inches_ = height;
    date_of_birth_ = DOB;
    gender_ = gender;
    age_ = age;
}


personType::personType(string firstName, string lastName) { // First+Last constructor
    name_ = firstName + " " + lastName;
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

personType::personType() { // Default constructor
    name_ = "Not Set";
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

personType::~personType() { // Destructor
    cout << "Destructor has been called" << endl;
}


bool compareStringCaseInsensitive(string string1, string string2) { // Stretch 3 (Case Insensitive Comparison)
    if (string1.size() != string2.size()) { // string1 and string2 aren't the same size
        return false;
    }

    for (size_t i = 0; i < string1.size(); i++) {
        if (
            static_cast<unsigned char>(tolower(string1[i])) !=
            static_cast<unsigned char>(tolower(string2[i]))
        ) {
            return false;
        }
    }
    return true;
}

void personType::print() const { // Stretch 2 (Formatted output)
    std::cout <<  left << setw(20) << " | Name: " << left << this->getName() << endl
        << left << setw(20) << " | Address: " << left << this->getAddress() << endl
        << left << setw(20) << " | Height: " << left << std::fixed << std::setprecision(1) << this->getHeight() << " in" << endl
        << left << setw(20) << " | DOB: " << left << this->getDOB() << endl
        << left << setw(20) << " | Gender: " << left << this->getGender() << endl
        << left << setw(20) << " | Age: " << left << static_cast<int>(this->getAge()) << endl;
}

bool personType::equals(const personType& other) const {
    // Circuited comparison
    if (!compareStringCaseInsensitive(this->getName(), other.getName())) {
        return false;
    }

    if (!compareStringCaseInsensitive(this->getAddress(), other.getAddress())) {
        return false;
    }

    if (this->getHeight() != other.getHeight())  {
        return false;
    }

    if (!compareStringCaseInsensitive(this->getDOB(), other.getDOB())) {
        return false;
    }

    if (
        static_cast<unsigned char>(tolower(this->getGender())) != // Case insensitive
        static_cast<unsigned char>(tolower(other.getGender()))
    ) {
        return false;
    }

    if (this->getAge() != other.getAge()) {
        return false;
    }

    return true;
}

    // Setters

    void personType::setName(string name) {
        name_ = name;
    }

    void personType::setAddress(string address) {
        address_ = address;
    }

    void personType::setHeight(double height) {
        if (height < 0 || height > 120) {
            height = 0;
        }

        height_inches_ = height;
    }

    void personType::setDOB(string DOB) {
        date_of_birth_ = DOB;
    }

    void personType::setGender(char gender) {
        gender_ = gender;
    }

    void personType::setAge(uint16_t age) {
        if (age > 999) {
            age = 0;
        }

        age_ = static_cast<uint16_t>(age);
    }

    // Getters

    string personType::getName() const { return name_; }
    string personType::getAddress() const { return address_; }
    double personType::getHeight() const { return height_inches_; }
    string personType::getDOB() const { return date_of_birth_; }
    char personType::getGender() const { return gender_; }
    uint16_t personType::getAge() const { return age_; }