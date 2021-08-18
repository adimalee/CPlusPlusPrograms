/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Composition
*/
  
#include <iostream> 
#include <string>
#include "personTypeHeaderFile.h"

using namespace std;

void personType::print() const
{
    cout << firstName << " " << lastName << endl;
    myPet.print();
}

void personType::setName(string first, string last, string setName, string setBreed, string setColor)
{
    myPet.set(setName, setBreed, setColor);
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType(string first, string last, string Name, string Breed, string Color) 		// Constructor
                              :myPet(Name, Breed, Color)
{ 
    firstName = first;
    lastName = last;
}
