/*
Name: Aditya Maleeswaran
Course: CSC 210
Date: 11/13/14
Timings: Thursdays; 6:00 - 9:30 PM
Chapter 17 - In Class Lab
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct ListOfWords
{
	string Input;
	ListOfWords *NextWord;
};

int main()
{
	
	ifstream infile;
    ListOfWords *FirstNode, *NewNode, *LastNode, *KeepTrack;
    string Word;
    bool FoundWord;
    
    infile.open("Input.txt");
    if(!infile)
    {
               cout << "Unable to open Input.txt \n";
               system ("pause");
               return 1;
    }
        
    FirstNode = NULL;
    	
	while (infile)
	{
		NewNode = new ListOfWords;
		infile >> NewNode -> Input;
		NewNode -> NextWord = NULL;
		
		if(FirstNode == NULL)
		{
			FirstNode = NewNode;
			LastNode = NewNode;
		}
		else
		{
			LastNode -> NextWord = NewNode;
			LastNode = NewNode;
		}
	}
	
	while(Word != "END")
	{
		FoundWord = false;
		KeepTrack = FirstNode;
		cout << "Please enter a word to search in the list or END to Exit: " << endl;
		cin >> Word;
		
		if(Word == "END")
		{
			continue;
		}
		
		while(KeepTrack != NULL && !FoundWord)
		{
			if(Word == KeepTrack -> Input)
			{
				FoundWord = true;
				cout << "The word searched is found in the list." << endl;
			}
			else
			{
				KeepTrack = KeepTrack -> NextWord;
			}
		}
		
		if(!FoundWord)
		{
			cout << "Sorry, the word was not found in the list." << endl;
		}
	}
	
	
	infile.close();
	system ("pause");
	return 0;
}
