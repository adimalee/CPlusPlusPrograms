/*
Documentation: 
Name: Aditya Maleeswaran
Date: 10/2/14
Course: CSC 210
Timings: 6:00 - 9:30 PM
Chapter 12 In-Class Lab - Dynamic Data
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Students
{
	string FirstName;
	string LastName;
	double GPA;
};

int main()
{
	int NumOfStudents = 4;
    ifstream inFile;
    
    Students *StudentPtr, *SavePtr;
	StudentPtr = new Students[NumOfStudents];
	SavePtr = StudentPtr;
	
	inFile.open("InputFile.txt");
	if(!inFile)
	{
		cout << "Unable to open the Input File. Please try again." << endl;
		return 0;
	}
	
	// Priming Read for End-Of-File Loop
	inFile >> StudentPtr->FirstName;
    inFile >> StudentPtr->LastName;
    inFile >> StudentPtr->GPA;
	
	while(inFile)
	{
                 StudentPtr++;
                 inFile >> StudentPtr->FirstName;
                 inFile >> StudentPtr->LastName;
                 inFile >> StudentPtr->GPA;
 }   // Close End-Of-File Loop
 
     StudentPtr = SavePtr;
 
	for(int i = 0; i < 4; i++)
	{
            cout << StudentPtr->FirstName << "   ";
            cout << StudentPtr-> LastName << "   ";
            cout << StudentPtr->GPA << "  " << endl;
            StudentPtr++;
 }
	
	StudentPtr = SavePtr;
	delete [] StudentPtr;
	
	system("pause");
	return 0;
}
