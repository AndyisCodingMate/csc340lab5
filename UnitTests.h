//
//  UnitTests.h
//  InheritancePolymorphism-codingLab
//
//  Created by Andy Poon on 28 November, 2023.
//

#ifndef UnitTests_h
#define UnitTests_h

#include "Person.h"
#include "Employee.h"

namespace NS_UTESTS{
using namespace NS_PersonEmployee;

//Let's follow the CPP core guidline and implement each unit test as an inline function.
//Here's an example:
inline
bool inline_example(){
     //a few lines of code
    return true;
}

//include the following unit tests for Person class.

//bool test_PersonDCon(); //test the default constructor Person
//bool test_PersonCCon();  //test the copy constructor of Person
//bool test_PersonCAssign(); //test the copy assignment operator of Person
bool test_PersonDCon() {
    Person* p = new Person();
    bool testResult = (p->getSSN() == 0 && p->getName() == "na");
    delete p;
    return testResult;
}

bool test_PersonCCon() {
    Person p1;
    p1.setName("Andy");
    Person p2 = p1; 
    return (p2.getName() == "Andy");
}

bool test_PersonCAssign() {
    Person p1;
    p1.setName("Andy");
    Person p2;
    p2 = p1; 
    return (p2.getName() == "Andy");
}



//include the following unit tests for Employee class.

//bool test_EmployeeDCon(); //test the default constructor Employee
//bool test_EmployeeCCon();  //test the copy constructor of Employee
//bool test_EmployeeCAssign(); //test the copy assignment operator of Employee
//bool test_mixedArray(); //test the free-standing function mixedArray()
bool test_EmployeeDCon(){
    Employee* e = new Employee();
    bool testResult = (e->getSSN() == 0 && e->getName() == "na" && e->getEmail() == "work@");
    delete e;
    return testResult;
}
bool test_EmployeeCCon(){
    Employee e1;
    e1.setEmail("work@google.com");
    Employee e2 = e1;
    return (e2.getEmail() == "work@google.com");
}
bool test_EmployeeCAssign(){
    Employee e1;
    e1.setEmail("work@google.com");
    Employee e2;
    e2 = e1;
    return (e2.getEmail() == "work@google.com");
}
bool test_mixedArray() {
    Person** testMixedArray = nullptr;
    int numPersons = 5;
    int numEmployees = 9;

    mixedArray(testMixedArray, numPersons, numEmployees);

    // Check if the mixedArray function properly creates an array with the expected number of elements
    bool testResult = (testMixedArray != nullptr);

    // Assuming each Person object has an 'getEmail()' method
    for (int i = 0; i < numPersons + numEmployees; ++i) {
        if (i < numPersons) {
            // For Persons
            if (testMixedArray[i]->getEmail() != "personal@gmail.com") {
                testResult = false;
                break;
            }
        } else {
            // For Employees
            if (testMixedArray[i]->getEmail() != "work@gmail.com") {
                testResult = false;
                break;
            }
        }
    }

    // Clean up the dynamically allocated memory to avoid memory leaks
    deleteMixedArray(testMixedArray, numPersons + numEmployees);

    return testResult;
}

//end-of namespace NS_UTESTS
}
#endif /* UnitTests_h */
