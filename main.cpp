//
//  main.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Andy Poon on 11/28/2023.
//

#include "Person.h"
#include "Employee.h"
#include "UnitTests.h"

#include "Person.h"
#include "Employee.h"
#include "UnitTests.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    using namespace NS_PersonEmployee;
    using namespace NS_UTESTS;

    // Run unit tests for Person class
    bool personDefaultConTest = test_PersonDCon();
    bool personCopyConTest = test_PersonCCon();
    bool personCopyAssignTest = test_PersonCAssign();

    std::cout << "Person Default Constructor Test: " << (personDefaultConTest ? "Passed" : "Failed") << std::endl;
    std::cout << "Person Copy Constructor Test: " << (personCopyConTest ? "Passed" : "Failed") << std::endl;
    std::cout << "Person Copy Assignment Test: " << (personCopyAssignTest ? "Passed" : "Failed") << std::endl;

    // Run unit tests for Employee class
    bool employeeDefaultConTest = test_EmployeeDCon();
    bool employeeCopyConTest = test_EmployeeCCon();
    bool employeeCopyAssignTest = test_EmployeeCAssign();
    bool mixedArrayTest = test_mixedArray();

    std::cout << "Employee Default Constructor Test: " << (employeeDefaultConTest ? "Passed" : "Failed") << std::endl;
    std::cout << "Employee Copy Constructor Test: " << (employeeCopyConTest ? "Passed" : "Failed") << std::endl;
    std::cout << "Employee Copy Assignment Test: " << (employeeCopyAssignTest ? "Passed" : "Failed") << std::endl;
    std::cout << "mixedArray Function Test: " << (mixedArrayTest ? "Passed" : "Failed") << std::endl;

    // Additional code to directly test your classes if needed

    return 0;
}
