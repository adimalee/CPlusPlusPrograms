/*
Documentation:
Name: Aditya Maleeswaran
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct LinkedListNode
{
	string FirstName;
	string LastName;
	string JobTitle;
	char EmploymentStatus;
	double HourlyWage;
	LinkedListNode *Next;
};

void OpenFileFunction(ifstream&);

LinkedListNode* Insert(LinkedListNode*, LinkedListNode*);

LinkedListNode* SearchFunction(LinkedListNode*, string);

void Print(LinkedListNode*);
