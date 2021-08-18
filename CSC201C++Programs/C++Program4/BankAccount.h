class BankAccount                               // Class File or .h File
{
      public:
             BankAccount ();                    // Default Constructor
             BankAccount (float a);              // Constructor with Argument
             void DepositToTheBank (float d);     // Transformer with Argument
             void WithdrawalFromTheBank (float w); // Transformer with Argument
             float AccountBalance () const;        // Observer for the Balance
             int Transactions () const;         // Observer for Transactions
             
             private:
                     float CurrentBalance;
                     int NmbrOfTransactions;
                     
};
