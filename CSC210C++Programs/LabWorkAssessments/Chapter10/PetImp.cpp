#include <iostream>
#include "Pet.h"

using namespace std;

Pet::Pet() {
  name = " ";
  color = " ";
  breed = " ";
}
Pet::Pet (string inName, string inBreed, string inColor) {
  name = inName;
  breed = inBreed;
  color = inColor;
}
void Pet::set(string setName, string setBreed, string setColor) {
  name = setName;
  breed = setBreed;
  color = setColor;
}
void Pet::print() {
  cout << "-----------------------------------------------" << endl;
  cout << "Breed: " << breed << " Color: " << color << " Name: " << name << endl;
}

