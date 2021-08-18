/*
Program Name: MainFileBankAccount.cpp
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
#include "BankAccount.h"                  // Bring in the header file
#include "CheckingAccount.h"			// Bring in the inherited header file

using namespace std;

int main()
{
	string AccName;																					// Declaring variables and initializing them to 0
	int AccNum, Constant, NumOfAcc = 0, MenuChoice = 0, count = 0, Option = 0, inAcct, j;
    char TransactionMethod;
	double Charge, InitialBalance, MinBal, SrvcChrg;

	CheckingAccount Customers[20];																	// Created an object of checking account of 20 elements


	while(MenuChoice != 4)																			// While loop for the main menu category
	{
		cout << "Hello, You entered a Menu Driven, Interactive Online Bank!" << endl;
		cout << "Please choose one of the option below to continue. " << endl;
		cout << "Choose '1' to create a new account. " << endl;
		cout << "Choose '2' to Print all accounts. " << endl;
		cout << "Choose '3' to Modify an account. " << endl;
		cout << "Choose '4' to Exit the Main Menu." << endl;
		cin >> MenuChoice;

		switch(MenuChoice)
		{
			case 1: 																				// Creates the account, minimum balance, and service charge
					Customers[NumOfAcc].SetBankAccount(AccName, InitialBalance, Charge);
					cout << "Please enter the amount for the minimum balance: " << endl;
					cin >> MinBal;
					Customers[NumOfAcc].setMinimumBalance(MinBal);
					cout << "Please enter the amount for the service charge: " << endl;
					cin >> SrvcChrg;
					Customers[NumOfAcc].setServiceCharge(SrvcChrg);
					NumOfAcc++;
					break;

			case 2: 																				// Prints all the accounts that has previously been created
					for(count = 0; count < NumOfAcc; count++)
					{
						cout << Customers[count];
					}				// End for loop
					break;

			case 3: 																				// Enters the sub-menu category and modifies the account
					cout << "Please enter an account number to modify." << endl;
					cout << "Note that the account numbers start with 0: " << endl;
					cin >> inAcct;																	// Ask the user for the account number to modify

					for(j = 0; j < NumOfAcc; j++)
					{
						if(inAcct == Customers[j].getAccountNumber())								// Checks to see if the account number matches in the account list
							break;
					}				// End for loop

					while (Option != 5)																// While loop for the sub-menu category
					{

						cout << "Your entered a Sub-menu Category." << endl;
						cout << "Please choose an option below to modify your account." << endl;
						cout << "Choose '1' to make a deposit transaction." << endl;
						cout << "Choose '2' to make a withdrawl transaction." << endl;
						cout << "Choose '3' to Print the balance in your account." << endl;
						cout << "Choose '4' to Update the balance with interest." << endl;
						cout << "Choose '5' to Exit the Submenu." << endl;
						cin >> Option;

						switch(Option)
						{
							case 1: 																// Deposits the value, updates it and prints the data
									float Value;
                                    cout << "Please enter the amount to deposit: " << endl;
                                    cin >> Value;
                                    Customers[j] + Value;											// Over-rided + operator in the bank account implementation file
									cout << Customers[j];
									break;

							case 2: 																// Withdraws the value, updates it and prints the data
									Customers[j].Withdraw();										// Over-rided withdraw method in the checking account implementation file
									cout << Customers[j];
									break;

							case 3:																	// Prints all the data
									cout << Customers[j];
									break;

							case 4:																	// Updates the balance and prints the data
									Customers[j].UpdateBalance();
									cout << Customers[j];
									break;

							case 5: 																// Exits the sub-menu of the while loop
									break;
						}			// End sub-menu switch statments
					}				// End sub-menu while loop
					break;

			case 4: 																				// Exits the main menu of the while loop
					break;

			default: 																				// Default case to check if it is invalid input cases
					cout << "Wrong Choice. Please choose from the options given above." << endl;
					break;

		}			// End main menu switch statments
	}				// End main menu while loop

	system("pause");
	return 0;
}
