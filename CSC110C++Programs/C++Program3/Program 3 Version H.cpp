/* 
   Program 3.cpp
   Aditya Maleeswaran
   Input: float
   Output: float
   Algorithm: At first, enter the number of rooms for this program to calculate 
   the installation cost and the total cost. Then input the values for length, 
   width, and cost per square foot. The result will be in dollars of how much 
   it costs for each room. 
*/
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

void getdata(int& length, int& width, float& costpersqfoot);
float InstallPrice (int length, int width, float costpersqfoot);
float TotalCost (int length, int width, float costpersqfoot, float installprice);

     const float LABOR_COST = 0.35;
     const float TAX_RATE = 0.05;  

int main()
{
    int length, width, count;
    float costpersqfoot, installprice, totalprice;  
        
    cout << "Please enter the rooms to be calculated? \n";
    cin >> count;
    
    for(int i = 1; i <= count; i++)
     {      
            
        getdata(length, width, costpersqfoot);
        installprice = InstallPrice (length, width, costpersqfoot);
        totalprice = TotalCost (length, width, costpersqfoot, installprice);
        
        }
           
    system ("pause");
    return 0;
} 

void getdata(int& length, int& width, float& costpersqfoot)
{
     
     cout << "Enter the value for length, width and cost per square foot respectfully. \n";
     cin >> length >> width >> costpersqfoot;

     return;
}

float InstallPrice (int length, int width, float costpersqfoot)
{
      float installprice = ((length*width*costpersqfoot)+(length*width*LABOR_COST));
         cout << "The Installation Cost is \n" << installprice << " Dollars" << endl;
         return (installprice); 
}

float TotalCost (int length, int width, float costpersqfoot, float installprice)
{
      float totalprice = ((length*width*costpersqfoot*TAX_RATE) + installprice);
      cout << "The Total Cost is \n" << totalprice << " Dollars" << endl;
      return (totalprice);
}
