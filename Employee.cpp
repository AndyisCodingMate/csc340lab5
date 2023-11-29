//
//  Employee.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Andy Poon on November 28, 2023
//


#include "Employee.h"

namespace NS_PersonEmployee{

//implement Employee's member functions and the two free-standing functions below
    Employee::~Employee(){
        delete[] sal_change_rates;
    }
    Employee::Employee():work_email("work@"), salary(0.0),cnt_sal_changes(10) {
            sal_change_rates = new double[cnt_sal_changes];
            for (int i = 0; i < cnt_sal_changes; i++) {
                sal_change_rates[i] = 0.0;
            }
            
    }

    Employee::Employee(const Employee& clone):Person(clone),work_email(clone.work_email), salary(clone.salary),cnt_sal_changes(clone.cnt_sal_changes){
            sal_change_rates = new double[cnt_sal_changes];
            for (int i = 0; i < cnt_sal_changes; i++) {
                sal_change_rates[i] = clone.sal_change_rates[i];
            }
    }
    Employee Employee::operator=(const Employee& rhs ){
            if (this != &rhs) {
                Person::operator=(rhs); 
                delete[] sal_change_rates;

                salary = rhs.salary;
                cnt_sal_changes = rhs.cnt_sal_changes;
                work_email = rhs.work_email;

                sal_change_rates = new double[cnt_sal_changes];
                for (int i = 0; i < cnt_sal_changes; i++) {
                    sal_change_rates[i] = rhs.sal_change_rates[i];
                }
            }
            return *this;
    }
    double Employee::getChangeRate( int i) const{
            i = i;
            if (i < cnt_sal_changes) {
                return sal_change_rates[i];
            }
            else {
                return -1.00;
            }
    }////return the i-th rate in the sal_change_rates array if i is valid; otherwise return -1.00
    int Employee::getCntSalChanges() const{
        return cnt_sal_changes;
    } //return cnt_sal_changes
    void Employee::setCntSalChanges(int new_cnt){
        cnt_sal_changes = new_cnt;
    } //new_cnt-->cnt_sal_changes
    string Employee::getEmail() const{
        return work_email;
    } //return work_email
    void Employee::setEmail( string new_email){
        work_email = new_email;
    } //new_email-->work_email
    string Employee::getTypeOfObj() const{
        return "Employee";
    } //return "Employee"

    void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees){
        arrayPersonEmp = new Person*[numPersons + numEmployees];
        for (int i = 0; i < numPersons; i++) {
            arrayPersonEmp[i] = new Person();
            arrayPersonEmp[i]->setEmail("personal@gmail.com");
            }
        for (int i = numPersons; i < numPersons + numEmployees; i++) {
            arrayPersonEmp[i] = new Employee();
            arrayPersonEmp[i]->setEmail("work@gmail.com");
            }   
    }
    void deleteMixedArray(Person** &arrayPersonEmp, int size ){
        for (int i = 0; i < size; ++i) {
            delete arrayPersonEmp[i];
        }
        delete[] arrayPersonEmp;
        arrayPersonEmp = nullptr; // Reset the pointer to nullptr to avoid dangling pointer
    }

}//end-of namespace NS_PersonEmployee
