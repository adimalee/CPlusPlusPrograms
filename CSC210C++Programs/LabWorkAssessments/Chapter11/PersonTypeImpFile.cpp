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

using namespace std;

void PersonType::print() const
{
    cout << "First Name = " << firstName << "    " << "Last Name = " << lastName;
}

void PersonType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string PersonType::getFirstName() const
{
    return firstName;
}

string PersonType::getLastName() const
{
    return lastName;
}

    //constructor
PersonType::PersonType(string first, string last) 

{ 
    firstName = first;
    lastName = last;
}

PersonType::PersonType()
{
                        firstName = "    ";
                        lastName = "     ";
}
