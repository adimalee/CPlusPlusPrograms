#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

struct students {
  string firstName;
  string lastName;
  float  gpa;
};

int main () {
  
  int index;
  ifstream inData;
//  students someStudents[4];
  students *studentPtr, *startStudentList;
  
  studentPtr = new students[4];
  startStudentList = studentPtr;
  
  inData.open("inFile.txt");
  if (!inData) {
    cout << "Could not open inFile.txt, exiting .. " << endl;
    return 0;
  }
  
  for (index = 0; index < 4; index++) {
    inData >> studentPtr->firstName;
    inData >> studentPtr->lastName;
    inData >> studentPtr->gpa;
  
    studentPtr++;
  }

  studentPtr = startStudentList;
  cout << fixed << showpoint << setprecision(2);
  cout << "Students -------------------------------" << endl;
  for (index = 0; index < 4; index++) {
    cout << "         Name: " << studentPtr->firstName << " " 
                              << studentPtr->lastName << "   " 
                              << studentPtr->gpa << endl;
    studentPtr++;
  }  
  
// Just as a demonstration, you can also use the array notation
// to access the array structure; just make sure you point to the
// beginning of the array  
  studentPtr = startStudentList;
  cout << fixed << showpoint << setprecision(2);
  cout << "Students -------------------------------" << endl;
  for (index = 0; index < 4; index++) {
    cout << "         Name: " << studentPtr[index].firstName << " " 
                              << studentPtr[index].lastName << "   " 
                              << studentPtr[index].gpa << endl;
  }  
  
  // Reset to the beginning of the list, otherwise
  // Memory will be released starting at the address
  // where the above loop left off
  // potentially causing a problem.  Remember, working with addresses
  studentPtr = startStudentList;
  startStudentList = NULL;
  delete [] studentPtr;

  system("pause");
}            
 
