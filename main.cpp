/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/

#include <iostream>
#include <iomanip>
#include "personType.h"

using namespace std;



int main() {

    // Init members & Stretch 4 (explicitly test setters & getters in main)

    personType p1;

    p1.setName("Sabrina Morales");
    p1.setAddress("662 S. Southhampton Avenue Vista, CA 92083");
    p1.setHeight(51.2);
    p1.setDOB("24 July 2017");
    p1.setGender('F');
    p1.setAge(20);

    personType p2("Elle", "Macdonald");

    p2.setAddress("84 Green Drive Tracy, CA 95376");
    p2.setHeight(52.3);
    p2.setDOB("17 September 2014");
    p2.setGender('F');
    p2.setAge(20);

    personType p3(
        "Hannah", "Finley", "8253 Linda Dr. Laguna Niguel, CA 92677", 49.8, 
        "13 September 2012", 'F', 20
    );

    personType p4(
        "Arabella", "Walter", 
        "7593 Wood St. Fountain Valley, CA 92708", 54.1, 
        "27 April 2010", 'F', 20
    );

    personType p5(
        "Kye", "Baird", 
        "8316 Lafayette Ave. North Hills, CA 91343", 55.8, 
        "28 November 2008", 'F', 20
    );

    // Stretch 1 (Heading)
    cout << left << setw(10) << setfill('-') << "" << " # personType class # " << left << setw(10) << setfill('-') << "" << endl;

    cout << setfill(' ');

    // Print personType member data

    p1.print(), p2.print(), p3.print(), p4.print(), p5.print();

    // Compare personType members

    cout << boolalpha;
    cout << left << setw(20) << "equals(p1, p2) = " << left << p1.equals(p2) << endl;
    cout << left << setw(20) << "equals(p3, p4) = " << left << p3.equals(p4) << endl;
    cout << left << setw(20) << "equals(p3, p3) = " << left << p3.equals(p3) << endl;
}