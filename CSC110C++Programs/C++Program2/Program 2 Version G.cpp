/* 
File Name: Program 2 "Box Dimensions"
Name: Aditya Maleeswaran
Input: float
Output: float
Description: The program calculates each of the formulas with the values of 
length, width, and depth. The while loop helps the program to continue to do as 
many calculations as possible until it is being stopped by the programmer.  
*/

#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
 
const char SENTINEL = 'Q';

int main()
{
    double length, width, depth;
    char choice; 
    float answer;
    
    cout << "Select a number code to calculate: ";
    cout << "\n              V for Volume";
    cout << "\n              A for Surface Area";
    cout << "\n              G for Girth+Depth : ";
    cin >> choice;
    
    while (choice != SENTINEL)
          {
                  cout << "Type in three numbers to be calculated: " ;
                  cin >> length >> width >> depth;
                                               
    switch (choice)
    {
           case 'V': 
                answer = length*width*depth;
                cout << "Volume is " << answer << endl;
                break;
           case 'A': 
                answer = (2*length*width + 2*width*depth + 2*length*depth);
                cout << "Surface Area is " << answer << endl;
                break;
           case 'G':
                answer = (2*length + 2*width) + depth;
                cout << "Grith+Depth is " << answer << endl;
                break;
                } // end of switch 
                
          cout << "Select a number code to calculate: ";
    cout << "\n              V for Volume";
    cout << "\n              A for Surface Area";
    cout << "\n              G for Girth+Depth : ";
    cin >> choice;      
} // end of the while loop

     system("pause");
     return 0;
}
