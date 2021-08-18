/*
Program Name: Assignment1.cpp
Name: Aditya Maleeswaran
Title: Program 1
Input: Requests an input and output file name from the user (Input.txt provided).
		The Output is name of your choice.
Output: Displays output on the console (cout) and writes output to the file name provided.
Description: This program translates a word or phrase using the ROT13 cipher.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <iomanip>
#include <cmath>												// Libraries Included

#include "Program1.h"											// Bring in the header file

using namespace std;

int main ()
{
	char Character, Text, TransChar;
	string InputFile, AllCharacters, OutputFile;

	ifstream infile;
    ofstream outfile;

    cout << "Enter the name of the Input File with '.txt' at the end of the name. \n";
    cin >> InputFile;
    infile.open(InputFile.c_str());									// Opens the Input File
    while(!infile)
    {
    	cout << "Incorrect file name. Please enter again. \n";		// Displays and asks the uers to enter the input file name again
    	cin >> InputFile;
    	infile.open(InputFile.c_str());
	}

    infile.get(Character);											// Priming Read for End-of-file Loop
    while (infile)													// End-of-file Loop
    {
    	Text = Rot13 (Character, TransChar);						// Calling the Rot13 function in the main function
    	AllCharacters = AllCharacters + Text;

          infile.get(Character);
    }																// Closed for End-of-File Loop

    WriteTranslatedChar (AllCharacters);							// Calling the WriteTranslatedChar function in the main function

    infile.close();													// Close the input file
    outfile.close();												// Close the output file
    system ("pause");
    return 0;
}																	// Closed for the main function

/*
Documentation for Rot13 function
Description: This function takes as input a character parameter to be translated and returns the translated character.
Signature: Return type - char
			name - Rot13
			parameters - char Letter and char TransChar
List of Parameters and its Representation: Letter represents the character that is being read from the input file.
											TransChar represents the character that the input character (Letter) is being translated into.
Description of the function return type as applicable: After execution of the function, each translated character is sent to the main function,
														where the function is being called to execute the next line.
*/

char Rot13 (char Letter, char TransChar)
{
		if(Letter == 'A')											// If-else statements to translate each character from the input file
		TransChar = 'N';
	else if(Letter == 'B')
		TransChar = 'O';
	else if(Letter == 'C')
		TransChar = 'P';
	else if(Letter == 'D')
		TransChar = 'Q';
	else if(Letter == 'E')
		TransChar = 'R';
	else if(Letter == 'F')
		TransChar = 'S';
	else if(Letter == 'G')
		TransChar = 'T';
	else if(Letter == 'H')
		TransChar = 'U';
	else if(Letter == 'I')
		TransChar = 'V';
	else if(Letter == 'J')
		TransChar = 'W';
	else if(Letter == 'K')
		TransChar = 'X';
	else if(Letter == 'L')
		TransChar = 'Y';
	else if(Letter == 'M')
		TransChar = 'Z';
	else if(Letter == 'N')
		TransChar = 'A';
	else if(Letter == 'O')
		TransChar = 'B';
	else if(Letter == 'P')
		TransChar = 'C';
	else if(Letter == 'Q')
		TransChar = 'D';
	else if(Letter == 'R')
		TransChar = 'E';
	else if(Letter == 'S')
		TransChar = 'F';
	else if(Letter == 'T')
		TransChar = 'G';
	else if(Letter == 'U')
		TransChar = 'H';
	else if(Letter == 'V')
		TransChar = 'I';
	else if(Letter == 'W')
		TransChar = 'J';
	else if(Letter == 'X')
		TransChar = 'K';
	else if(Letter == 'Y')
		TransChar = 'L';
	else if(Letter == 'Z')
		TransChar = 'M';
	else
	{
		cout << "Incorrect Character!";
		cout << "Please use the 26 Letters of the Alphabet without any spaces in order to translate it into ROT 13.";
		cout << endl;
	}

	return TransChar;													// Returns the translated character to the main function
}																		// Closed for the Rot13 function

/*
Documentation for WriteTranslatedChar function
Description: This function will take as input a character to be 'output' to an output filestream, which should also be a parameter.
Signature: Return type - void
			name - WriteTranslatedChar
			parameters - string AllCharacters
List of Parameters and its Representation: AllCharacters represents the string of characters that has to be in the console (cout)
											and output file after the translation.
Description of the function return type as applicable: Since this function's main work is to output all the characters to the output file,
														the return type would be void. It does not return anything to the main function.
*/

void WriteTranslatedChar (string AllCharacters)
{
	ofstream outfile;
	string OutputFile;

	cout << "Enter the name of the Output File below. \n";			// Displays and asks the user to enter an output file name
    cin >> OutputFile;
	outfile.open(OutputFile.c_str());                                         // Opens the output file
    while(!outfile)
    {
    	outfile.clear();
    	cout << "Unable to open Output File.txt \n";            // Display error message if unable to open the output file
    	cout << "Enter a proper name again. \n";				// Displays and asks the user to to enter the output file name again
		cin >> OutputFile;
    	outfile.open(OutputFile.c_str());
    }

	cout << AllCharacters << endl;								// Outputs the string of characters to the console (cout)
	outfile << AllCharacters << endl;							// Outputs the string of characters to the output file

}																// CLosed for the WriteTranslatedChar function
