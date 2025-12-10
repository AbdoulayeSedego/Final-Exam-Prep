#include <iostream>
#include <string>
using namespace std;

// BankAccount class demonstrating OOP fundamentals
class BankAccount {
private:
    // Private data members (encapsulation)
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Default constructor - initializes balance to 0
    BankAccount() {
        accountNumber = "000000";
        accountHolder = "Unknown";
        balance = 0.0;
    }

    // Parameterized constructor - takes all three values
    BankAccount(string accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        // Validate initial balance
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Warning: Negative initial balance not allowed. Set to 0." << endl;
        }
    }

    // Deposit function - adds to balance with validation
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
    }

    // Withdraw function - subtracts from balance with validation
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." << endl;
        } else if (amount > balance) {
            cout << "Error: Insufficient funds. Current balance: $" << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Display all account information
    void displayInfo() {
        cout << "------------------------" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    cout << "=== Bank Account System ===" << endl << endl;

    // Create account using default constructor
    cout << "Creating Account 1 (default constructor):" << endl;
    BankAccount account1;
    account1.displayInfo();

    // Create account using parameterized constructor
    cout << "\nCreating Account 2 (parameterized constructor):" << endl;
    BankAccount account2("ACC-12345", "John Doe", 500.00);
    account2.displayInfo();

    // Perform deposits
    cout << "\n--- Performing Deposits ---" << endl;
    cout << "Account 1: ";
    account1.deposit(250.00);
    cout << "Account 2: ";
    account2.deposit(150.00);

    // Perform valid withdrawals
    cout << "\n--- Performing Withdrawals ---" << endl;
    cout << "Account 1: ";
    account1.withdraw(100.00);
    cout << "Account 2: ";
    account2.withdraw(200.00);

    // Display updated balances
    cout << "\n--- Updated Account Info ---" << endl;
    cout << "Account 1:" << endl;
    account1.displayInfo();
    cout << "\nAccount 2:" << endl;
    account2.displayInfo();

    // Test error handling
    cout << "\n--- Testing Error Handling ---" << endl;

    // Attempt invalid withdrawal (insufficient funds)
    cout << "Attempting to withdraw $1000 from Account 1 (balance: $"
         << account1.getBalance() << "):" << endl;
    account1.withdraw(1000.00);

    // Attempt negative deposit
    cout << "\nAttempting negative deposit (-$50) to Account 2:" << endl;
    account2.deposit(-50.00);

    // Attempt negative withdrawal
    cout << "\nAttempting negative withdrawal (-$20) from Account 2:" << endl;
    account2.withdraw(-20.00);

    // Final balances using getBalance()
    cout << "\n--- Final Balances (using getBalance()) ---" << endl;
    cout << "Account 1 Balance: $" << account1.getBalance() << endl;
    cout << "Account 2 Balance: $" << account2.getBalance() << endl;

    return 0;
}
