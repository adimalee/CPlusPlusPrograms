/* 
Program 1.cpp
Aditya Maleeswaran
Type of Input: Float
Type of Output: Int
Description: First, enter the amount of coins or change that you have right now in dollars.
Then, it converts the decimal value into an integer. 
Finally, it gives you the result in Quarters, Dimes, Nickels, and Pennies.
*/

#include <iostream> 
using namespace std;

int main(void)
{
    float coins;
    int temp, quarters, dimes, nickels, pennies;
    
    cout<< "How much money do you have in dollars right now?\n";
    cin>> coins;
    temp = (coins*100)+ 0.01;
    cout<< "Total coins: "<< temp << " Cents\n";
    
    quarters = temp / 25;
    cout<<"" << quarters << " Quarters\n";
    temp = temp % 25;
    
    dimes = temp / 10;
    cout<<"" << dimes << " Dimes\n";
    temp = temp % 10;
    
    nickels = temp / 5;
    cout<<"" << nickels << " Nickels\n";
    temp = temp % 5;
    
    pennies = temp;
    cout<< "Lastly " << pennies << " Pennies\n";
    
    system("pause");
    return 0;
    
}
    
