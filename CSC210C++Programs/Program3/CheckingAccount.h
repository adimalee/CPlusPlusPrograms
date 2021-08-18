/*
Program Name: CheckingAccount.h
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

#ifndef CheckingAccount_H
#define CheckingAccount_H

#include "BankAccount.h"

using namespace std;

class CheckingAccount: public BankAccount
{
	friend ostream& operator<<(ostream&, const CheckingAccount&);  // Override the (put to) Insertion operator
    public:
			CheckingAccount();         								// Default Constructor
            double getMinimumBalance();		             			// Observer
			double getServiceCharge();			         			// Observer
			void setMinimumBalance(double MinBal = 5.0);            // Transformer
			void setServiceCharge(double SrvcChrg = 1.0);			// Transformer
			void Withdraw();						             	// Transformer
			void print();						             		// Observer

	private:
			double MinimumBalance;					// Variable to store minimum balance
			double ServiceCharge;					// Variable to store monthly service charge
};

#endif
