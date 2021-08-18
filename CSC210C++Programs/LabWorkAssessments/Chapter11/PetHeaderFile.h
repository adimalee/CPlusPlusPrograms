/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Composition
*/

#ifndef PetHeaderFile_H
#define PetHeaderFile_H

#include <string>

using namespace std;

class Pet 
{
    public:
    	Pet();
    	Pet(string,string,string);
    	void set(string, string, string);
    	void print()const;
    	
    private:
    	string breed;
    	string name;
    	string color;	
};

#endif
