#define PARENT_H

#include <iostream>

using namespace std;

class Car 
{
public:
	virtual void Print();
	Car();
private:
	string carType;
};
#endif

