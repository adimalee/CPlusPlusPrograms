/*
Program Name: BankAccount.cpp
Name: Aditya Maleeswaran
Title: Program 2
Input: Requests the user for their account name, account number, and their
transaction method.
Output: Displays the output on the console (cout) of their account name,
number, and their current balance after the transaction method.
Description: This program is an interactive, menu driven program that takes
about 20 customer information one at a time. The customer has to provide their
account name, number, and their transaction method. Their transaction method
includes if it is a deposit or withdrawl from the account. Then, it charges the
user with an interest and updates the balance. Finally, it outputs their account
name, number, and their balance after the update.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "BankAccount.h"

using namespace std;

/*
This is a default constructor. It assigns all the values to 0 in the begginning
of the program when the object is declared. It does not have any return type or
parameters.
*/
int BankAccount::AccNum = 0;

BankAccount::BankAccount()                              // Default Constructor
{
	AccountName = " ";
    AccountNumber = 0;
    CurrentBalance = 0;
    Interest = 0;
}

/*
This is a constructor. It has the same name as the class name. It has four
parameters (string AccName, int AccNum, float Initial Balance, float charge).
These parameters are being passed by value and are assigned to their respective
variables.
*/

BankAccount::BankAccount(string AccName, int AccNum, float InitialBalance, float Charge)       // Constructor
{
	AccountName = AccName;
    AccountNumber = AccNum;
    CurrentBalance = InitialBalance;
    Interest = Charge;
}

/*
This is an observer that gets the Account Name and is being returned as a string.
It does not have any parameters passed to the function.
*/

string BankAccount::getAccountName() const                 // Observer
{
       return AccountName;
}

/*
This is an observer that gets the Account Number and is being returned as an
integer. It does not have any parameters passed to the function.
*/

int BankAccount::getAccountNumber() const                  // Observer
{
       return AccountNumber;
}

/*
This is an observer that gets the Interest and is being returned as a float.
It does not have any parameters passed to the function.
*/

float BankAccount::getInterest() const                     // Observer
{
      return Interest;
}

/*
This is an observer that gets the Initial or Current Balance and is being
returned as a float. It does not have any parameters passed to the function.
*/

float BankAccount::getCurrentBalance() const               // Observer
{
      return CurrentBalance;
}

/*
This is a transformer that asks the user for the details and sets the Bank
Account. It has four parameters that are passed by value. The return type is a
void and the function name should be different from the class.
*/

void BankAccount::SetBankAccount(string AccName, float InitialBalance, float Charge)  // Transformer
{
	cout << "Please enter your account name." << endl;
	cin >> AccName;
    //cout << "Please enter your account number." << endl;
    //cin >> AccNum;
    cout << "Please enter your initial balance. " << endl;
    cin >> InitialBalance;
    cout << "Please enter the interest to be charged (in %). " << endl;
    cin >> Charge;


    AccountName = AccName;
	AccountNumber = AccNum++;
	CurrentBalance = InitialBalance;
	Interest = Charge;
}

/*
This is a transformer that asks for the deposit value and stores the result
into the current balance. The return type is void and it doesn't have any
parameters passed to the function.
*/

void BankAccount::Deposit()                                  // Transformer
{
	float Value;
    cout << "Please enter the amount to deposit: " << endl;
    cin >> Value;
    CurrentBalance = CurrentBalance + Value;
}

/*
This is a transformer that asks for the withdrawl value and stores the result
into the current balance. The return type is void and it doesn't have any
parameters passed to the function.
*/

void BankAccount::Withdraw()                                // Transformer
{
	float Value;
    cout << "Please enter the amount to withdraw: " << endl;
    cin >> Value;
    if(Value > CurrentBalance)
	{
             cout << "You cannot withdraw more than your intial balance in your account" << endl;
    }
    else
    {
        CurrentBalance = CurrentBalance - Value;
    }
}

/*
This is a transformer that updates the account by multiplying the current
balance with the interest being charged. Since the interest is in percent, it
calculates the value to decimal and then updates the account. The return type
is void and it doesn't have any parameters passed to the function.
*/

void BankAccount::UpdateBalance()                         // Observer
{
	Interest = Interest / 100;
    CurrentBalance += CurrentBalance * Interest;
}

/*
This is an observer that prints or outputs the account name, account number,
and your current balance in your account using the get function. The return
type is void and it doesn't usually have any parameters passed to the function.
*/

void BankAccount::Print() const                                  // Observer
{
	cout << "Account Name is: " << getAccountName() << endl;
	cout <<  "Account Number is: " << getAccountNumber() << endl;
    cout << "The current balance in your account is: " << getCurrentBalance() << endl;
}
