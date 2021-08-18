/*
Name: Aditya Maleeswaran
Course: CSC 210
Timings: 6:00 - 9:30 PM
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main ()
{
	string FileName, OutputData;
	bool Found = false;
	ifstream inFile;
	
	string Message;
	
	Message = "Sorry, the file was not found.";
	
	do
	{
		try
		{
			cout << "Enter a file name to search and output the data. " << endl;
			cout << "Don't forget to add .txt at the end of the file name. " << endl;
			cin >> FileName;
			cout << endl;
			
			inFile.open(FileName.c_str());
			
			if(!inFile)
			{
				throw Message;
			}
			
			Found = true;
			cout << "The file has been found and the data is as follows: " << endl;
			cout << endl;			
		}
		catch (string MessageStr)
		{
			cout << MessageStr << endl;
			inFile.clear();
			inFile.ignore(100, '\n');
			cout << "Please enter the correct file name again: " << endl;
		}
	}
	while (!Found);
	
	getline(inFile, OutputData);
	
	cout << OutputData << endl;
	
	system ("pause");
	return 0;
}
