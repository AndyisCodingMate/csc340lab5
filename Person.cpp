//
//  Person.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Andy Poon
//

#include "Person.h"
#include <iostream>
#include <string>

namespace NS_PersonEmployee {

        int SSN;
        std::string name;
        std::string personalEmail;
        int cntPlaces;
        std::string* placesVisited;

        // Constructor, Destructor, Copy Constructor, Assignment Operator
        Person::Person() : SSN(0), name("na"), personalEmail("personal@"), cntPlaces(10) {
            try {
                placesVisited = new std::string[cntPlaces];
                for (int i = 0; i < cntPlaces; i++) {
                    placesVisited[i] = "unknown";
                }
            }
            catch (const std::bad_alloc& ba) {
                std::cout << "bad_alloc caught: " << ba.what() << std::endl;
            }
        }

        Person::~Person() {
            delete[] placesVisited; // Free allocated memory
        }

        Person::Person(const Person& clone) : SSN(clone.SSN), name(clone.name), personalEmail(clone.personalEmail), cntPlaces(clone.cntPlaces) {
            try {
                placesVisited = new std::string[cntPlaces];
                for (int i = 0; i < cntPlaces; i++) {
                    placesVisited[i] = clone.placesVisited[i];
                }
            }
            catch (const std::bad_alloc& ba) {
                std::cout << "bad_alloc caught: " << ba.what() << std::endl;
            }
        }

        Person Person::operator=(const Person& rhs) {
            if (this != &rhs) { // Check for self-assignment
                SSN = rhs.SSN;
                name = rhs.name;
                personalEmail = rhs.personalEmail;
                cntPlaces = rhs.cntPlaces;
                delete[] placesVisited; // Deallocate existing memory
                try {
                    placesVisited = new std::string[cntPlaces];
                    for (int i = 0; i < cntPlaces; i++) {
                        placesVisited[i] = rhs.placesVisited[i];
                    }
                }
                catch (const std::bad_alloc& ba) {
                    std::cout << "bad_alloc caught: " << ba.what() << std::endl;
                }
            }
            return *this;
        }

        // Getter and Setter Methods
        void Person::setSSN(int ssn) {
            SSN = ssn;
        }

        int Person::getSSN() {
            return SSN;
        }

        void Person::setName(string name) {
            this->name = name;
        }

        std::string Person::getName() {
            return name;
        }

        std::string Person::getPlace(int i)const {
            i = i;
            if (i < cntPlaces) {
                return placesVisited[i];
            }
            else {
                return "out-of-boundary";
            }
        }

        std::string Person::getEmail() const {
            return personalEmail;
        }

        void Person::setEmail(std::string new_email) {
            personalEmail = new_email;
        }

        std::string Person::getTypeOfObj() const {
            return "Person";
        }


} // end-of namespace NS_PersonEmployee
