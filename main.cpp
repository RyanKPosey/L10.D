/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/

#include <iostream>
#include <iomanip>
#include "personType.h"
#include <vector>
#include "selectionSort.h"

using namespace std;



int main() {

    // Init members & Stretch 4 (explicitly test setters & getters in main)
    vector<personType> people = {
        personType("Ada", "Lovelace", "12 Grosvenor Sq, London", 65.0, "1815-12-10", 'F', 27),
        personType("Alan", "Turing", "43 Warrington Cres, London", 70.0, "1912-06-23", 'M', 24),
        personType("Grace", "Hopper", "Harvard Univ, Cambridge, MA", 64.0, "1906-12-09", 'F', 47),
        personType("John", "von Neumann", "Institute for Advanced Study, Princeton", 69.0, "1903-12-28", 'M', 39),
        personType("Donald", "Knuth", "Stanford University, Palo Alto, CA", 72.0, "1938-01-10", 'M', 30),
        personType("Barbara", "Liskov", "MIT CSAIL, Cambridge, MA", 63.0, "1939-11-07", 'F', 50),
        personType("Margaret", "Hamilton", "MIT Instrumentation Lab, Cambridge, MA", 66.0, "1936-08-17", 'F', 33),
        personType("Tim", "Berners-Lee", "CERN, Geneva, Switzerland", 71.0, "1955-06-08", 'M', 34),
        personType("Dennis", "Ritchie", "Bell Labs, Murray Hill, NJ", 69.0, "1941-09-09", 'M', 33),
        personType("Brian", "Kernighan", "Bell Labs, Murray Hill, NJ", 71.0, "1942-01-01", 'M', 36),
        personType("Linus", "Torvalds", "Helsinki, Finland", 70.0, "1969-12-28", 'M', 21),
        personType("Steve", "Wozniak", "Cupertino, CA", 68.0, "1950-08-11", 'M', 26),
        personType("Steve", "Jobs", "Cupertino, CA", 67.0, "1955-02-24", 'M', 29),
        personType("Bill", "Gates", "Redmond, WA", 69.0, "1955-10-28", 'M', 30),
        personType("Katherine", "Johnson", "NASA Langley, Hampton, VA", 63.0, "1918-08-26", 'F', 50),
        personType("Radia", "Perlman", "Digital Equipment Corp, Boston, MA", 65.0, "1951-12-18", 'F', 34),
        personType("Vint", "Cerf", "Stanford University, Palo Alto, CA", 70.0, "1943-06-23", 'M', 33),
        personType("Ken", "Thompson", "Bell Labs, Murray Hill, NJ", 71.0, "1943-02-04", 'M', 28),
        personType("James", "Gosling", "Sun Microsystems, Mountain View, CA", 73.0, "1955-05-19", 'M', 39),
        personType("Hedy", "Lamarr", "Hollywood, CA", 67.0, "1914-11-09", 'F', 26)
    };

    char choice;

    do {
        cout << "1: Print Tallest\n2: print oldest\n3: print youngest\n4: selection sort" << endl;
        cin >> choice;

        switch (choice) {
            case '1': {
                int tallestIndex = personType::getTallest(people);
                if (tallestIndex != -1) {
                    cout << "Tallest person is at index " << tallestIndex << ":" << endl;
                    people[tallestIndex].print();
                } else {
                    cout << "No people in the list." << endl;
                }
            } break;
            case '2': {
                int oldestIndex = personType::getOldest(people);
                if (oldestIndex != -1) {
                    cout << "Oldest person is at index " << oldestIndex << ":" << endl;
                    people[oldestIndex].print();
                } else {
                    cout << "No people in the list." << endl;
                }
            } break;
            case '3': {
                int youngestIndex = personType::getYoungest(people);
                if (youngestIndex != -1) {
                    cout << "Youngest person is at index " << youngestIndex << ":" << endl;
                    people[youngestIndex].print();
                } else {
                    cout << "No people in the list." << endl;
                }
            } break;
            case '4': {
                char sortKey;
                cout << "Enter sort key\na: First Name\nb: Last Name\nc: Height\nd: Address\ne: Age\nf: DOB\ng: Gender\nh: Last Name then First Name): ";
                cin >> sortKey;
                selectionSort(people, sortKey);
            }
            break;
            case '5': {
                cout << "Exiting..." << endl;
                return 0;
            } break;
            default: {
                cout << "Invalid choice. Please try again." << endl;
            } break;
        }

        for (const auto& person : people) {
            person.print();
            cout << endl;
        }
    } while (choice != '5');
}