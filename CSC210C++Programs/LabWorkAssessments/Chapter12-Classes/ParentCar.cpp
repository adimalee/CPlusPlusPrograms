#include <iostream>
#include <cstdlib>
#include <iomanip>

include "Parent.h"

using namespace std;
 
Car::Car(){
	carType = "Ford";
}
void Car::Print()
{
	cout << "The car is a " << carType << endl;
	cout << "========================" << endl;
}


