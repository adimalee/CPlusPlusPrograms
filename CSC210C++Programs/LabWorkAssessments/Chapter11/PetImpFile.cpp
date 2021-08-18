/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Composition
*/

#include <iostream>
#include "PetHeaderFile.h"

using namespace std;

Pet::Pet() 
{
	name = " ";
	color = " ";
	breed = " ";
}

Pet::Pet (string inName, string inBreed, string inColor) 
{
	name = inName;
	breed = inBreed;
	color = inColor;
}

void Pet::set(string setName, string setBreed, string setColor) 
{
	name = setName;
	breed = setBreed;
	color = setColor;
}

void Pet::print() const
{
	cout << "-----------------------------------------------" << endl;
	cout << "Breed: " << breed << " Color: " << color << " Name: " << name << endl;
}
