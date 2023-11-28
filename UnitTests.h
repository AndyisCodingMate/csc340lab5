//
//  UnitTests.h
//  InheritancePolymorphism-codingLab
//
//  Created by xyz on dmy.
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



//include the following unit tests for Employee class.

//bool test_EmployeeDCon(); //test the default constructor Employee
//bool test_EmployeeCCon();  //test the copy constructor of Employee
//bool test_EmployeeCAssign(); //test the copy assignment operator of Employee
//bool test_mixedArray(); //test the free-standing function mixedArray()

}//end-of namespace NS_UTESTS

#endif /* UnitTests_h */
