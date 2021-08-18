#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 20;
const int FSIZE = 30;
int getMax(int[]);

int main() {
  int numbers[SIZE], max, i;
  char fileName[FSIZE];
  ifstream inFile;

  cout << "Please enter the file name " << endl;
  cin >> fileName;
  inFile.open(fileName);
  if (!inFile) {
    cout << "File name is mispelled or does not exist " << endl;
    return 0;
  }

  for (i = 0; i < SIZE; i++)
    inFile >> numbers[i];

  max = getMax(numbers);

  cout << "The maximum value is " << max << " for the array that contains: " << endl;
  for (i = 0; i < SIZE; i++)
    cout << numbers[i] << " " << endl;

  system("pause");
}

int getMax(int inArray[]) {
  int max = inArray[0];

  for (int i = 1; i < SIZE; i++){
    if (inArray[i] > max)
      max = inArray[i];
  }

  return max;
}
