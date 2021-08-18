/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Composition
*/

#ifndef personTypeHeaderFile_H
#define personTypeHeaderFile_H

#include <string>

#include "PetHeaderFile.h"

using namespace std;

class personType
{
	public:
		void print() const;
		//Function to output the first name and last name
		//in the form firstName lastName.
		
		void setName(string first, string last, string Name, string Breed, string Color);
		//Function to set firstName and lastName according 
		//to the parameters.
		//Postcondition: firstName = first; lastName = last
		
		string getFirstName() const;
		//Function to return the first name.
		//Postcondition: The value of firstName is returned.
		
		string getLastName() const;
		//Function to return the last name.
		//Postcondition: The value of lastName is returned.
		
		personType(string first = "", string last = "", string Name = "", string Breed = "", string Color = "");
		//Constructor
		//Sets firstName and lastName according to the parameters.
		//The default values of the parameters are null strings.
		//Postcondition: firstName = first; lastName = last  
		
	private:
		string firstName; //variable to store the first name
		string lastName;  //variable to store the last name
		Pet myPet;
};

#endif
