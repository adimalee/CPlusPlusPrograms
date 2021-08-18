/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Inheritance
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PersonType.h"
#include "DoctorType.h" 

using namespace std;

int main()
{
    PersonType student("Lisa", "Regan");

    student.print();

    cout << endl;
    
    DoctorType MyStudent("Jennifer", "Allison", "Nurse");
    
    MyStudent.print();
    
    cout <<  endl;
    
    system("pause");
    return 0;
}
