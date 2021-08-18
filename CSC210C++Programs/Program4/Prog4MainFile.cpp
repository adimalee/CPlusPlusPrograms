/*
Documentation:
Name: Aditya Maleeswaran
Title: Program 4
Input: Requests the user for the employee's first and last name, job title,
employment status, and the hourly wage. It also asks for the last name to
search in the list of input data.
Output: Displays the output on the console (cout) of the employee's first and
last name, job title, employment status, and the hourly wage. It also outputs
the searched information by their last name.
Description: This program is a menu driven program that reads in the information
from the input file. Not only it reads in the data from the file, but also promts
the user to insert new information of the new employees when the user choses option
number 1. Then, we can search an employee's last name to check if it is in the list
stored by choosing option number 3. It also outputs the information of all the
employees if the user choses option number 3 from the menu. Finally, option number 4
exits the menu driven program.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>

#include "Prog4HeaderFile.h"

using namespace std;

int main()
{
	LinkedListNode *FirstNode, *NewNode;
	string Word, SearchItem;
	int MenuChoice;
	bool FoundWord;
	ifstream inFile;

	FirstNode = NULL;

	OpenFileFunction(inFile);																	// Call the open file function

	while(inFile)																				// Read in the data from the input file
	{
		NewNode = new LinkedListNode;
		inFile >> NewNode -> FirstName;
		inFile >> NewNode -> LastName;
		inFile >> NewNode -> JobTitle;
		inFile >> NewNode -> EmploymentStatus;
		inFile >> NewNode -> HourlyWage;
		NewNode -> Next = NULL;
		FirstNode = Insert(FirstNode, NewNode);
	}

	while(MenuChoice != 4)																			// While loop for the menu category
	{
		cout << "Hello, please choose an option from the Menu!" << endl;
		cout << "Choose '1' to insert information. " << endl;
		cout << "Choose '2' to search the information of the employees by their last name. " << endl;
		cout << "Choose '3' to print the information of all the employees. " << endl;
		cout << "Choose '4' to exit from the menu." << endl;
		cin >> MenuChoice;

		switch(MenuChoice)
		{
			case 1: 																				// Option Number 1
					NewNode = new LinkedListNode;
					cout << "Enter the first name of the employee: ";
					cin >> NewNode -> FirstName;
					cout << "Enter the last name of the employee: ";
					cin >> NewNode -> LastName;
					cout << "Enter the job title in one word: ";
					cin >> NewNode -> JobTitle;
					cout << "Enter the employement status ('P' for Part time or 'F' for Full time): ";
					cin >> NewNode -> EmploymentStatus;
					cout << "Enter in the hourly wage in decimal value: ";
					cin >> NewNode -> HourlyWage;
					NewNode -> Next = NULL;
					FirstNode = Insert(FirstNode, NewNode);											// Call the Insert Function to insert new information provided by the user
					break;

			case 2: 																				// Option Number 2
					cout << "Please enter the last name to search for the employee: ";
					cin >> SearchItem;
					FirstNode = SearchFunction(FirstNode, SearchItem);								// Call the Search Function
					Print(FirstNode);																// Call the Print Function
					break;

			case 3: 																				// Option Number 3
					Print(FirstNode);																// Call the Print Function
					break;
			case 4: 																				// Option Number 4
					break;																			// Exits the menu driven program
			default:
					cout << "Wrong Choice. Please choose from the options given above." << endl;
					break;

		}			// End main menu switch statments
	}				// End menu while loop


	system ("pause");
	return 0;
}

void OpenFileFunction(ifstream& inFile)																// Open File Function Definition and Body of the program as follows
{
	string FileName, Message;
	bool Found = false;

	Message = "Sorry, unable to find the file.";

	do
	{
		try
		{
			cout << "Enter a file name to search. " << endl;
			cout << "Don't forget to add '.txt' at the end of the file name." << endl;
			cin >> FileName;
			cout << endl;

			inFile.open(FileName.c_str());

			if(!inFile)
			{
				throw Message;
			}

			Found = true;
			cout << "The file has been found!" << endl;
			cout << endl;
		}
		catch(string MessageStr)
		{
			cout << MessageStr << endl;
			inFile.clear();
			inFile.ignore(100, '\n');
			cout << "Please enter the correct file name again: " << endl;
		}
	}
	while (!Found);

}


LinkedListNode* Insert(LinkedListNode* FirstNode, LinkedListNode* NewNode) 							// Insert Function Definition and Body of the program as follows
{
	LinkedListNode *Chase, *Current, *LastNode;
	bool FoundWord = false;

	if (FirstNode == NULL)
	{
		FirstNode = NewNode;
		LastNode = NewNode;
	}
	else
	{
		Current = FirstNode;
		FoundWord = false;
		while (Current != NULL && !FoundWord)
		{
			if (Current -> LastName >= NewNode -> LastName)
			{
				FoundWord = true;
			}
			else
			{
				Chase = Current;
				Current = Current -> Next;
			}
		}

		if (Current == FirstNode)
		{
			NewNode -> Next = FirstNode;
			FirstNode = NewNode;
		}
		else
		{
			Chase -> Next = NewNode;
			NewNode -> Next = Current;

			if (Current == NULL)
			{
				LastNode = NewNode;
			}
		}
	}

  return FirstNode;
}

LinkedListNode* SearchFunction(LinkedListNode* FirstNode, string SearchItem)						// Search Function Definition and Body of the program as follows
{
	LinkedListNode *Current;
	bool FoundWord = false;
	Current = FirstNode;

	while(Current != NULL && !FoundWord)
	{
		if(Current -> LastName == SearchItem)
		{
			FoundWord = true;
		}
		else
		{
			Current = Current -> Next;
		}
	}
	return Current;
}

void Print(LinkedListNode* FirstNode)																// Print Function Definition and Body of the program as follows
{
	LinkedListNode *Current;
	Current = FirstNode;

	while(Current != NULL)
	{
		cout << Current -> FirstName << "	";
		cout << Current -> LastName << "	";
		cout << Current -> JobTitle << "	";
		cout << Current -> EmploymentStatus << "	";
		cout << Current -> HourlyWage << "	" << endl;
		Current = Current -> Next;

	}
}

