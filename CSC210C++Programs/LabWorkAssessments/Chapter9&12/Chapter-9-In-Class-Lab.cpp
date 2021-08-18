#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Chapter-9-Lab.h"

using namespace std;

int main() {

  studentType students[NOSTUDENTS];
  ifstream inFile;

  inFile.open("inPut.txt");
  if (!inFile) {
    cout << "inPut.txt open failed...exiting " << endl;
    return 0;
  }

  processFile(inFile, students);
  outputData(students);

  system("pause");
}
void processFile(ifstream& inData, studentType inStudent[]){

  for (int i = 0; i < NOSTUDENTS; i++){
    inData >> inStudent[i].firstName >> inStudent[i].middleName >> inStudent[i].lastName;
    inData >> inStudent[i].registrationDate.month >> inStudent[i].registrationDate.day;
    inData >> inStudent[i].registrationDate.year >> inStudent[i].birthDate.month;
    inData >> inStudent[i].birthDate.day >> inStudent[i].birthDate.year;
    inData >> inStudent[i].gpa;
  }
}
void outputData(const studentType outStudent[]){

  for (int i = 0; i < NOSTUDENTS; i++){
    cout << "Student Name: " << outStudent[i].firstName << " " << outStudent[i].middleName << " " <<
      outStudent[i].lastName << endl;
    cout << "Registration Date: " << outStudent[i].registrationDate.month << " " <<
      outStudent[i].registrationDate.day << " " << outStudent[i].registrationDate.year << endl;
    cout << "Birth Date: " << outStudent[i].birthDate.month << " " << outStudent[i].birthDate.day << " " <<
      outStudent[i].birthDate.year << "  GPA: " << outStudent[i].gpa << endl << endl;
  }
}
