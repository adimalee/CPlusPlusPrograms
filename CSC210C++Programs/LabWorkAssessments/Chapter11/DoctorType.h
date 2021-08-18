/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Inheritance
*/

#ifndef DoctorType_H
#define DoctorType_H

#include "PersonType.h"

using namespace std;

class DoctorType: public PersonType
{
      public: 
              DoctorType();             // Default Constructor
              DoctorType(string first, string last, string Spec);   // Constructor
              string getSpeciality();
              void setSpeciality(string first, string last, string Spec);
              void print() const;              // Observer
              
      private:
              string Speciality;
              
};

#endif
