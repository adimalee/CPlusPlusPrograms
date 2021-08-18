#ifndef SEDAN_H
#define SEDAN_H

#include <iostream>
#include "Parent.h"

using namespace std;

class Sedan: public Car {
public:
	Sedan();
	void Print() ;
private:
	string thisCar;
};
#endif
