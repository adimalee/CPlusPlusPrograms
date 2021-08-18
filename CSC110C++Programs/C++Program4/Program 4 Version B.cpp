/* 
   Program 4 Version B.cpp
   Aditya Maleeswaran
   Input: Int
   Output: Int and Float
   Algorithm: Enter the number of array values to be read. Then enter 
   the array values by hitting enter after each value. Not only the result will 
   be shown, but also the average value for those values, minimum index number, 
   and the first number rotated one space to the left. 
*/

#include <iostream>
using namespace std;

const int ArraySize = 50;

void getlist(int [], int&);
void putlist(const int[], int);
float mean_average(const int[], int);
int MinIndex(const int[], int);
void left_rotate (int[], int); 

int main() 
{
    int list[ArraySize];
    int num_vals; 
    int smallestNum_index;
    float average;
    
    getlist(list,num_vals);
    putlist(list,num_vals);
    average = mean_average(list,num_vals);
    cout << "\nThe average of those values are " << average << endl;
    smallestNum_index = MinIndex(list,num_vals);
    cout << "The minimum value is " << smallestNum_index << endl;
    left_rotate(list,num_vals);
    putlist(list,num_vals);
    
    system ("pause");
    return 0;
}

void getlist(int list[], int& num_vals)
{
     int i;
     
     cout << "Enter the number of array values to be read \n";
     cin >> num_vals;
     
     for(i = 0; i < num_vals; i++)
     {
           cout << "Now, enter the next array value \n";
           cin >> list[i];
     }
}

void putlist(const int list[], int num_vals)
{
     cout << "The array elements are as follows:\n"; 
     
     for(int i = 0; i < num_vals; i++)
     {
             cout << i << " " << list[i] << endl;
     }
}

float mean_average(const int list[], int num_vals)
{
      int i;
      float total;
              
      for(i = 0; i < num_vals; i++)
      
            total = (list[i] + total);
            
     return (total / num_vals);
         
}

int MinIndex(const int list[], int num_vals)
{
    int i, min;
    int smallestNum_index = 0;
    min = list[0];
        
    for(i = 0; i < num_vals; i++)
    {
          if (min > list[i])
          {
                  min = list[i];
                  smallestNum_index = i;
          }                
    }
    
    return(smallestNum_index);
}

void left_rotate (int list[], int num_vals)
{
     int num_1 = list[0], i;
     
     for(i = 0; i < num_vals - 1; i++)
     {
             list[i] = list[i+1];
     }
             list[num_vals - 1] = num_1;
}
