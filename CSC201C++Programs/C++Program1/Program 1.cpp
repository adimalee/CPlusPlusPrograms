/*
File Name: Program 1 "Calculate Grade"
Name: Aditya Maleeswaran
Input: Reads the data from a file
Output: Writes updated data in an output file
Description: This program reads a series of integers from the input file which
includes a student's grades in a class. It outputs the final exam, hourly exams,
homework, programs, total numeric grade, and letter grade for that class. The
output is produced as a table in both the output window as well as the output file.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NUMHOMEWORK = 7;
const int MAXHOMEWORK = NUMHOMEWORK - 1;
const int NUMPROGRAMS = 4;
const float MAXPROGRAMS = 400.0;
const char ASCIICONVERT = 0X0F;

int main()
{
    ifstream infile;
    ofstream outfile;

    char ch;
    int finalexam, intval, HourlyExam1, HourlyExam2, HourlyExam3,
    hw = 0, hw2, hw3, hw4, hw5, hw6, hw7, pg1, pg2, pg3, pg4,
    LowestExamGrd, TotalHrlyExams, TotalPrgms;
    int FinalGrade = 0;

    infile.open("File.txt");
    if(!infile)
    {
               cout << "Unable to open file.txt \n";
               system ("pause");
               return 1;
    }
    outfile.open("Outfile.txt");
    if(!outfile)
    {
                cout << "Unable to open Outfile.txt \n";
                system ("pause");
                return 1;
    }

    // Heading for each column are displayed here.
    outfile << setw(9) << "Final Exam";
    cout << setw(9) << "Final Exam";
    outfile << setw(15) << "Hourly Exam";
    cout << setw(15) << "Hourly Exam";
    outfile << setw(10) << "Homework";
    cout << setw(10) << "Homework";
    outfile << setw(13) << "Programs";
    cout << setw(13) << "Programs";
    outfile << setw(18) << "Number Grade";
    cout << setw(18) << "Number Grade";
    outfile << setw(14) << "Letter Grade" << endl;
    cout << setw(14) << "Letter Grade" << endl;

    infile >> finalexam;
    while (infile)
    { // Open while loop
          // Calculations for Final Exam are displayed here.
          outfile << setw(6) << finalexam;
          cout << setw(6) << finalexam;
          finalexam = (finalexam * 25);

          // Calculations for Hourly Exams are displayed here.
          for(int x = 0; x < 3; x++)
          { // Open for loop
                  infile >> intval;
                  if(x == 0)
                  {
                       HourlyExam1 = intval;
                       outfile << setw(10) << HourlyExam1;
                       cout << setw(10) << HourlyExam1;
                  }
                  else if(x == 1)
                  {
                       HourlyExam2 = intval;
                       outfile << setw(4) << HourlyExam2;
                       cout << setw(4) << HourlyExam2;
                  }
                  else if(x == 2)
                  {
                       HourlyExam3 = intval;
                       outfile << setw(4) << HourlyExam3;
                       cout << setw(4) << HourlyExam3;
                  }
          } // Close for loop

          // Calculations for Lowest Hourly Exam Grade.
          if ((HourlyExam1 < HourlyExam2) && (HourlyExam1 < HourlyExam3))
          {
                           LowestExamGrd = HourlyExam1;
          }
          else if ((HourlyExam2 < HourlyExam1) && (HourlyExam2 < HourlyExam3))
          {
               LowestExamGrd = HourlyExam2;
          }
          else if ((HourlyExam3 < HourlyExam2) && (HourlyExam3 < HourlyExam1))
          {
               LowestExamGrd = HourlyExam3;
          }
          else
          {
              outfile << "Nothing was found." << endl;
          }

          // Found out the lowest exam grade.
          TotalHrlyExams = ((HourlyExam1 + HourlyExam2 + HourlyExam3) - LowestExamGrd);
          // Found out the total hourly exams.
          TotalHrlyExams = ((TotalHrlyExams / 2) * 45);

          // Calculations for Homework are displayed here.
          for(int y = 0; (y < NUMHOMEWORK); y++)
          { // Open for loop
                  infile >> ch;

                  if(ch == '1')
                  {
                        hw++;
                  }
          } // Open for loop

          outfile << setw(8) << hw;
          cout << setw(8) << hw;
          if(hw == NUMHOMEWORK)
          {
                hw = MAXHOMEWORK - 1;
          }
          hw = ((hw * 100) / MAXHOMEWORK) * 10;

          //Calculations for Programs are done here.
          for(int z = 0; z < 4; z++)
          { // Open for loop
                  infile >> intval;

                  if(z == 0)
                  {
                       pg1 = intval;
                       outfile << setw(7) << pg1;
                       cout << setw(7) << pg1;
                  }
                  else if(z == 1)
                  {
                       pg2 = intval;
                       outfile << setw(4) << pg2;
                       cout << setw(4) << pg2;
                  }
                  else if(z == 2)
                  {
                       pg3 = intval;
                       outfile << setw(4) << pg3;
                       cout << setw(4) << pg3;
                  }
                  else if(z == 3)
                  {
                       pg4 = intval;
                       outfile << setw(4) << pg4;
                       cout << setw(4) << pg4;
                  }
          } // Close for loop

          TotalPrgms = (pg1 + pg2 + pg3 + pg4);
          TotalPrgms = (TotalPrgms / NUMPROGRAMS)* 20;
          // Found out total programs here.

          // Calculations for Final Numerical Grade are displayed here.
          FinalGrade = (TotalPrgms + hw + finalexam + TotalHrlyExams) / 100;
          outfile << setw(10) << FinalGrade;
          cout << setw(10) << FinalGrade;

          // Calculations for Letter Grade are displayed here.
          if(FinalGrade < 60)
          {
                        outfile << setw(13) << "F" << endl;
                        cout << setw(13) << "F" << endl;
          }
          else if(FinalGrade < 70)
          {
               outfile << setw(13) << "D" << endl;
               cout << setw(13) << "D" << endl;
          }
          else if(FinalGrade < 80)
          {
               outfile << setw(13) << "C" << endl;
               cout << setw(13) << "C" << endl;
          }
          else if(FinalGrade < 90)
          {
               outfile << setw(13) << "B" << endl;
               cout << setw(13) << "B" << endl;
          }
          else if(FinalGrade < 100)
          {
               outfile << setw(13) << "A" << endl;
               cout << setw(13) << "A" << endl;
          }

          hw = 0;

          infile >> finalexam;
    } // Close while loop

    infile.close();
    outfile.close();
    system ("pause");
    return 0;
}
