// Create a class Pets.  This class should have member variables:  name,
//  breed, color
// This class should have two constructors:  (1) default that sets the member
//  variables to blank  (2) one that sets the member values to the values
//  in the constructor parameters
// This class should have the following member functions:
//  set - sets the member variables to the values in the function parameters
//  print - prints the member variables
// Create a class defintion file (*.h)
//        a class implementation file (*.cpp)
//        a client program to test your class
//        a project for these code files
//  The client program should:
//    create a Pet object using the default constructor
//    create a Pet object using the constructor with parameters
//    create a Pet object array of 3 components and set the member variables
//      for each array component appropriately
//  Print EACH pet object

#include <iostream>
#include "Pet.h"

using namespace std;

int main() {
  Pet apet;
  Pet bpet("Tsia", "Mastiff-Burnese", "Black", 1);
  Pet somepets[3];
  Pet cpet("Kira", "Beagle", "Brown", 1);

  somepets[0].set("Harper", "Rottweiler", "Black-Brown", 1);
  somepets[1].set("Andy", "Beagle", "Brown-White", 1);
  somepets[2].set("Phelix", "Parrot", "Green", 1);
  
  apet.print();
  bpet.print();
  cpet.print();
  
  for (int i = 0; i < 3; i++) {
    somepets[i].print();
  }
  cout << endl;
  
  cpet = cpet + 3;
  cpet.print();
  
  system("pause");
  return 0;
}
