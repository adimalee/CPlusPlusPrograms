#include <iostream>
#include "Pet.h"

using namespace std;

Pet::Pet() {
  name = " ";
  color = " ";
  breed = " ";
  numpets = 0;
}
Pet::Pet (string inName, string inBreed, string inColor, int inNumPets) {
  name = inName;
  breed = inBreed;
  color = inColor;
  numpets = inNumPets;
}
void Pet::set(string setName, string setBreed, string setColor, int setNumPets) {
  name = setName;
  breed = setBreed;
  color = setColor;
  numpets = setNumPets;
}
void Pet::print() {
  cout << "-----------------------------------------------" << endl;
  cout << "Breed: " << breed << " Color: " << color << " Name: " << name << " Number: " << numpets << endl;
}
Pet Pet::operator+ (int amt) 
{
        
    numpets = numpets + amt;

    return *this;
}


