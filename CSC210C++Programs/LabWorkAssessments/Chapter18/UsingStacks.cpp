//Test Program 
  
#include <iostream>
#include "linkedStack.h"

using namespace std;
 
int main() 
{
	linkedStackType<int> stack1;
	linkedStackType<int> stack2;

	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);
	stack1.push(3);
	stack1.push(29);
	stack1.push(82);

	stack1.reverseStack(stack2);

	cout << "stack1: ";

	while (!stack1.isEmptyStack())
	{
		cout << stack1.top() << " ";
		stack1.pop();
	}

	cout << endl;

	cout << "stack2: ";

	while (!stack2.isEmptyStack())
	{
		cout << stack2.top() << " ";
		stack2.pop();
	}

	cout << endl;

	return 0;
}

