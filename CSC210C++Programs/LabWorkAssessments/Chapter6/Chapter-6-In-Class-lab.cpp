// chapter 6 in class lab - a solution
#include<iostream>
#include<cstdlib>

using namespace std;

void increase(int&,int&);
int increase(int);

int main() {

  int response = 0, rem, odd, counter = 0;

  while (1) {
    cout << "Please enter an integer.  A odd integer will be doubled; an even integer will be tripled. " << endl;
    cout << "Enter -1 to quit " << endl;
    cin >> response;
    if (response == -1)
      break;
    else {
      rem = response % 2;//determines if number is even or odd
      if (rem) {
        odd = increase(response);
        cout << "The value " << response << " was doubled: " << odd << endl;
      }
      else {
        cout << "The value " << response;
        increase(response, counter);
        cout <<  " was tripled: " << response << endl;
        cout << "The triple function called " << counter << " times " << endl;
      }
    }
  }
  system("pause");
}
void increase(int& tripled, int& c) {
  c++;

  tripled *= 3;

}
int increase (int doubled) {
  static int counter = 0;
  counter++;

  doubled *= 2;

  cout << "The doubled function called " << counter << " times " << endl;
  return doubled;
}
