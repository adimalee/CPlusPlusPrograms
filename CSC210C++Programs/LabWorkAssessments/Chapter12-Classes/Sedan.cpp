#inlcude <iostream>
#include <iomanip>
#include <cstdlib>
#include "Parent.h"
#include "Sedan.h"

using namespace std;

Sedan::Sedan(){
  thisCar = "Sedan";
}
void Sedan::Print() {
	Car::Print();
	cout << "This car is a " << thisCar << endl;
	cout << "========================" << endl;
}

