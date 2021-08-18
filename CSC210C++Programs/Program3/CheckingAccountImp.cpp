/*
Program Name: CheckingAccountImp.cpp
Name: Aditya Maleeswaran
Title: Program 3
Input: Requests the user for their account name, account number, minimum balance,
service charge, interest and their transaction method.
Output: Displays the output on the console (cout) of their account name,
number, and their minimum balance after the transaction method and the service
charge method.
Description: This program is an interactive, menu driven program that takes
about 20 customer information one at a time. The customer has to provide their
account name, number, service charge, minimum balance, interest and their
transaction method. Their transaction method includes if it is a deposit or
withdrawl from the account. Then, it charges the user with an interest and
updates the balance. Finally, it outputs their account name, number, and their
balance after the update.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "BankAccount.h"
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount()           										 // Default Constructor
                                       :BankAccount ()
{
	MinimumBalance = 0;
	ServiceCharge = 0;
}

double CheckingAccount::getMinimumBalance()             							// Observer
{
	return MinimumBalance;
}

double CheckingAccount::getServiceCharge()                   						// Observer
{
	return ServiceCharge;
}

void CheckingAccount::setMinimumBalance(double MinBal)								// Transformer
{
	if(MinBal < 5.0)																// Checks to see if the minimum balance is greater than $5 in the account
	{
              MinBal = 5.0;
    }
    MinimumBalance = MinBal;
}

void CheckingAccount::setServiceCharge(double SrvcChrg)								// Transformer
{
	if(SrvcChrg <= 1.0)																// Checks to see if the service charge is greater than $1
	{
                SrvcChrg = 1.0;
    }
    ServiceCharge = SrvcChrg;
}

void CheckingAccount::Withdraw()													// Transformer
{
    double CrntBal;
    double WithdrawlValue;
    CrntBal = BankAccount::getCurrentBalance();										// Over-rided withdraw method from the bank account class

	cout << "Please enter the amount to withdraw: " << endl;
    cin >> WithdrawlValue;
    if((WithdrawlValue + ServiceCharge) > CrntBal)
    {
                       cout << "Your withdrawl has been denied because you cannot withdraw more than your balance in your account. " << endl;
    }
    else
    {
         CrntBal -= WithdrawlValue;
    }
    if(CrntBal < MinimumBalance)
    {
               CrntBal -= ServiceCharge;
    }
    BankAccount::SetCurrentBalance(CrntBal);
}

ostream& operator<<(ostream& OutObj, const CheckingAccount& BAObject)      			// Overriding Insertion Operator method
{
       BAObject.Print();
       return OutObj;
}

