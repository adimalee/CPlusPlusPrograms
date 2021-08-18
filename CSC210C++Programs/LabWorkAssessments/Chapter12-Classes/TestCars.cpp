#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Parent.h"
#include "Sedan.h"

using namespace std;

void printem(Car&);
int main() {
 
	Car x;
	x.Print();
 
	Sedan y;
	y.Print();
	
	printem(x);
	printem(y);
}
void printem(Car& z) {
	z.Print();
}
