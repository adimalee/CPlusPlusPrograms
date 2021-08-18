/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 11 - In Class Lab - Composition
*/
 
#include <iostream> 
#include <string>
#include <cstdlib>

#include "personTypeHeaderFile.h"
 
using namespace std;

int main()
{
	personType NewPerson("Abraham", "Lincoln", "Dog", "Dalmatian", "White");
	
	NewPerson.print();
	
	cout << endl;
	
	system("pause");
	return 0;
}
