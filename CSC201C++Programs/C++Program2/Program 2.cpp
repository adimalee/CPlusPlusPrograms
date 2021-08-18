/*
File Name: Program 2 "Harris Benedict Equation"
Name: Aditya Maleeswaran
Input: Reads the values from the file
Output: Writes the calculated values in the output file
Description: This program reads the values from the input file. The input file includes
Weight, Height, Age, Sex, and Activity Level of a person. With the calculations of
Harris Benedict principle, the program outputs the BMR value and the Total Calories
that the person took to maintain the current weight in the output file.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void getdata (int&, int&, int&, char&, int&, std::ifstream&, std::ofstream&); // Prototypes
int BMRCalc (int, int, int, char);
int CaloriesCalc (int, int);

int main()
{
    int BMR;
    int Weight, Height, Age, ActivityLevel;
    char MaleOrFemale;
    float DailyCals;
    ifstream infile;
    ofstream outfile;

    infile.open("Harris Benedict Formula.txt");
    if(!infile)
    {
               cout << "Unable to open Harris Benedict Formula.txt \n";
               system ("pause");
               return 1;
    }
    outfile.open("Output File.txt");
    if(!outfile)
    {
                cout << "Unable to open Output File.txt \n";
                system ("pause");
                return 1;
    }

    outfile << setw(7) << "Weight";
    outfile << setw(7) << "Height";
    outfile << setw(5) << "Age";
    outfile << setw(5) << "M/F";
    outfile << setw(16) << "Activity Level";
    outfile << setw(10) << "BMR";
    outfile << setw(20) << "Total Calories" << endl;

    getdata (Weight, Height, Age, MaleOrFemale, ActivityLevel, infile, outfile);
    while (infile)
    {
          outfile << setw (5) << Weight;
          cout << setw(5) << Weight;
          outfile << setw(7) << Height;
          cout << setw(7) << Height;
          outfile << setw(6) << Age;
          cout << setw(6) << Age;
          outfile << setw(5) << MaleOrFemale;
          cout << setw(5) << MaleOrFemale;
          outfile << setw(12) << ActivityLevel;
          cout << setw(12) << ActivityLevel;

          BMR = BMRCalc (Weight, Height, Age, MaleOrFemale); // Calling the funtion
          outfile << setw(15) <<BMR;
          DailyCals = CaloriesCalc (ActivityLevel, BMR);
          outfile<< setw(15) << DailyCals <<endl;
          getdata (Weight, Height, Age, MaleOrFemale, ActivityLevel, infile, outfile);
    } // closed for End-Of-File Loop

    infile.close();
    outfile.close();
    system ("pause");
    return 0;
} // Closed for main funtion

void getdata (int& Weight, int& Height, int& Age, char& MaleOrFemale, int& ActivityLevel,
std::ifstream& infile, std::ofstream& outfile) // Funtion Definition
{
     infile /*>> setw(5)*/ >> Weight;
     infile /*>> setw(7)*/ >> Height;
     infile /*>> setw(7)*/ >> Age;
     infile /*>> setw(4)*/ >> MaleOrFemale;
     infile /*>> setw(7)*/ >> ActivityLevel;
     return;
} // Closed for getdata function

int BMRCalc (int Weight, int Height, int Age, char MaleOrFemale)
{
     char M, F;
     int BMR;
     if (MaleOrFemale == 'M')
     {
           BMR = 66+(6.23 * Weight)+(12.7 * Height)-(6.76 * Age);
     }
     else if (MaleOrFemale == 'F')
     {
          BMR = 655+(4.35 * Weight)+(4.7 * Height)-(4.7 * Age);
     }
     cout << setw(15) << BMR;

    return BMR;
} // Closed for BMRCalc funtion

int CaloriesCalc (int ActivityLevel, int BMRCalc)
{
      int DailyCals;
     switch (ActivityLevel)
     {
            case 1 : DailyCals = BMRCalc * 1.2;                     // Level 1: Little or no exercise
                     cout << setw(15) << DailyCals << endl;
                     break;
            case 2 : DailyCals = BMRCalc * 1.375;                   // Level 2: Little Exercise
                     cout << setw(15) << DailyCals << endl;
                     break;
            case 3 : DailyCals = BMRCalc * 1.55;                    // Level 3: Moderate Exercise
                     cout << setw(15) << DailyCals << endl;
                     break;
            case 4 : DailyCals = BMRCalc * 1.725;                     // Level 4: Heavy Exercise
                     cout << setw(15) << DailyCals << endl;
                     break;
            case 5 : DailyCals = BMRCalc * 1.9;                     // Level 5: Very Heavy Exercise
                     cout << setw(15) << DailyCals << endl;
                     break;
     }
     return DailyCals;
} // Closed for CaloriesCalc funtion

