
#include <iostream>
#include <cstdlib>
#include "PetHeaderFile.h"

using namespace std;

int main() {
  Pet apet;
  Pet bpet("Tsia", "Mastiff-Burnese", "Black");
  Pet somepets[3];

  somepets[0].set("Harper", "Rottweiler", "Black-Brown");
  somepets[1].set("Andy", "Beagle", "Brown-White");
  somepets[2].set("Phelix", "Parrot", "Green");
  
  apet.print();
  bpet.print();
  
  for (int i = 0; i < 3; i++) {
    somepets[i].print();
  }
  cout << endl;
  
  system("pause");
}
