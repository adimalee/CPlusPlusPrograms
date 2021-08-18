/*
Program Name: BankAccount.h
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

using namespace std;

class BankAccount
{
	public:
		BankAccount();					                // Default Constructor
		BankAccount(string, int, float, float);	        // Constructor
		string getAccountName() const;                  // Observer
		int getAccountNumber() const;                   // Observer
		float getInterest() const;                      // Observer
		float getCurrentBalance() const;                // Observer
        void SetBankAccount(string, float, float); // Transformer
		void Deposit();                                 // Transformer
		void Withdraw();                                // Transformer
		void UpdateBalance();                           // Transformer
		void Print() const;				                // Observer

	private:
		string AccountName;                    // Variable to store Account Name
		int AccountNumber;                     // Vairable to store Account Number
		float CurrentBalance;                  // Variable to store the Balance
        float Interest;                        // Variable to store Interest being charged
		static int AccNum;
};

