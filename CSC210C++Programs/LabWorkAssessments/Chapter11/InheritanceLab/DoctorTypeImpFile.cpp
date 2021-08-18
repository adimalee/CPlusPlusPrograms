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

DoctorType::DoctorType()
{
             Speciality = " ";            
}

DoctorType::DoctorType(string first, string last, string Spec)
               : PersonType(first, last)
{
                        Speciality = Spec;
}

string DoctorType::getSpeciality()
{
     return Speciality;
}

void DoctorType::setSpeciality(string first, string last, string Spec)
{
     PersonType::setName(first, last);
     
     Speciality = Spec;
}

void DoctorType::print() const
{
     PersonType::print();
     cout << "           Speciality = " << Speciality << endl;
}
