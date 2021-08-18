#include <iostream>                                 // Implementation File
#include <fstream>                                  // Libraries
#include <iomanip>

using namespace std;

#include "BankAccount.h"                            // Include Specification

BankAccount::BankAccount ()                         // Default Constructor
{
      CurrentBalance = 1000;
      NmbrOfTransactions = 0;                 // Initial Balance in the Bank
}

BankAccount::BankAccount (float a)                       // Constructor # 2
{
            CurrentBalance = a;
            NmbrOfTransactions = 0;
}

void BankAccount::DepositToTheBank(float d)              // Transformer # 1
{
     CurrentBalance = CurrentBalance + d;
     NmbrOfTransactions++;
}

void BankAccount::WithdrawalFromTheBank (float w)        // Transformer # 2
{
     if (w > CurrentBalance)
     {
        cout << "ERROR!!! Unable to do the Transaction." << endl;
     }
     else
     {
         NmbrOfTransactions++;
         CurrentBalance = CurrentBalance - w;
     }
}

float BankAccount::AccountBalance () const               // Observer # 1
{
      return CurrentBalance;      
}

int BankAccount::Transactions () const                   // Observer # 2
{
    return NmbrOfTransactions;    
}
