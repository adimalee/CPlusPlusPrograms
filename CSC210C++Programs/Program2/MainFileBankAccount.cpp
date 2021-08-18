/*
Program Name: MainFileBankAccount.cpp
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
#include "BankAccount.h"                  // Bring in the header file

using namespace std;

int main()
{
	string AccName;
	int AccNum, Constant, NumOfAcc = 0, MenuChoice = 0, count = 0, Option = 0, inAcct, j;
    char TransactionMethod;
	float Charge, InitialBalance;

	BankAccount Customers[NumOfAcc];

	cout << "How many accounts do you plan to create? " << endl;
	cin >> NumOfAcc;

	while(MenuChoice != 4)
	{
		cout << "Hello, You are entering a Menu Driven, Interactive Online Bank!" << endl;
		cout << "Please choose one of the option below to continue. " << endl;
		cout << "Choose '1' to create a new account. " << endl;
		cout << "Choose '2' to Print all accounts. " << endl;
		cout << "Choose '3' to Modify an account. " << endl;
		cout << "Choose '4' to Exit the Main Menu." << endl;
		cin >> MenuChoice;

		switch(MenuChoice)
		{
			case 1:
					Customers[NumOfAcc].SetBankAccount(AccName, InitialBalance, Charge);
					NumOfAcc++;
					break;

			case 2:
					for(count = 0; count < NumOfAcc; count++)
					{
						Customers[count].Print();
					}
					break;

			case 3:
					cout << "Please enter an account number to modify: " << endl;
					cin >> inAcct;

					for(j = 0; j < NumOfAcc; j++)
					{
						if(inAcct == Customers[j].getAccountNumber())
							break;
					}

					while (Option != 5)
					{

						cout << "Your entering a Sub-menu Category." << endl;
						cout << "Please choose an option below to modify your account." << endl;
						cout << "Choose '1' to make a deposit transaction." << endl;
						cout << "Choose '2' to make a withdrawl transaction." << endl;
						cout << "Choose '3' to Print the balance in your account." << endl;
						cout << "Choose '4' to Update the balance with interest." << endl;
						cout << "Choose '5' to Exit the Submenu." << endl;
						cin >> Option;

						//for(int k = 0; k < NumOfAcc; k++)
						//{

						switch(Option)
						{
							case 1:
									Customers[j].SetBankAccount(AccName, InitialBalance, Charge);
									Customers[j].Deposit();
									Customers[j].Print();
									break;

							case 2:
									Customers[j].SetBankAccount(AccName, InitialBalance, Charge);
									Customers[j].Withdraw();
									Customers[j].Print();
									break;

							case 3:
									Customers[j].Print();
									break;

							case 4:
									Customers[j].SetBankAccount(AccName, InitialBalance, Charge);
									Customers[j].UpdateBalance();
									Customers[j].Print();
									break;

							case 5:
									break;
						}
						//}
					}
					break;

			case 4:
					return 0;
					break;

			default:
					cout << "Wrong Choice. Please choose from the options given above." << endl;
					break;

		}
	}

	system("pause");
	return 0;
}

