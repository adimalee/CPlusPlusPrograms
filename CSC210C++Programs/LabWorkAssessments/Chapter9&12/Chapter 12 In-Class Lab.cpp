#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
  int x, y;
  int *p, *q;
  char s[10] = "abcde";
  char *cptr;
  
  x = 2;
  y = 8;
  
  p = &x;
  q = &y;
  
  cout << "Address of x: " << &x << " Value of x  " << x << endl;
  cout << "Value of   p: " << p  << " Value of *p " << *p << endl;
  cout << "Address of y: " << &y << " Value of y  " << y << endl;
  cout << "Value of   q: " << p  << " Value of *q " << *p << endl;
  cout << "Address of p: " << &p << " Address of q " << &q << endl;
  
  cout << endl;
  cptr = s+4 ;
  
  for (int i = 5; i > 0; i--)
    cout << "Char " << *cptr-- << " ";
  
  cout << endl;
  system("pause");
}
