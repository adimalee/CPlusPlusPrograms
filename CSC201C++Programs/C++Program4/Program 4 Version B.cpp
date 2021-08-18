/*
File Name: Program 4 Version B, "Bank Account"
Name: Aditya Maleeswaran
Input: The program reads in the letters and values from the input file.
Output: It outputs not only the values you wanted to deposit and withdraw
from the input file but also the number of transactions and current balance
in the bank.
Description: This program is to use a simple class and different files for
implementing a class. It reads the values that a user wants to deposit and
withdraw from their account. Then it outputs the values along with the number
of transactions and the current balance in their account.
*/

#include <iostream>                     // Libraries
#include <fstream>
#include <iomanip>
#include "BankAccount.cpp"              // Bring in the Implementation File

using namespace std;                    // Introduces namespace std


int main (void)
{
    BankAccount Account2(2000);

    char Choice;
    float Value;

    ifstream infile;
    ofstream outfile;

    infile.open("Input File.txt");
    if(!infile)
    {
               cout << "Unable to open Input File.txt \n";
               system ("pause");
               return 1;
    }
    outfile.open("Output File.txt");
    if(!outfile)
    {
                cout << "Unable to open Output File.txt \n";
                system ("pause");
                return 1;
    }

    infile >> Choice >> Value;                          // Priming Read
    while (infile)                                      // End of File Loop
    {
          if (Choice == 'd' || Choice == 'D')
          {
               cout << "The value that you prefered to deposit is: ";
               cout << Value << endl;
               outfile << "The value that you prefered to deposit is: ";
               outfile << Value << endl;
               Account2.DepositToTheBank(Value);
          }
          else if (Choice == 'w' || Choice == 'W')
          {
              cout << "The value that you wanted to withdraw is: ";
              cout << Value << endl;
              outfile << "The value that you wanted to withdraw is: ";
              outfile << Value << endl;
              Account2.WithdrawalFromTheBank (Value);
          }
          else
          {
               cout << "This transaction is Invalid!!!" << endl;
               outfile << "This transaction is Invalid!!!" << endl;
          }

          infile >> Choice >> Value;
    } // Closed for the End-Of-File Loop

    cout << "The Current Balance is: " << Account2.AccountBalance () << endl;
    outfile << "The Current Balance is: " << Account2.AccountBalance () << endl;

    cout << "The Number of Transaction(s): " << Account2.Transactions () << endl;
    outfile << "The Number of Transaction(s): " << Account2.Transactions () << endl;

    infile.close ();
    outfile.close ();
    system ("pause");
    return 0;

}   // Closed for the Main funtion
