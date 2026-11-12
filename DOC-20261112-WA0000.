#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string customerName;
    double balance;

    int depositCount;
    int withdrawalCount;
    int rejectedCount;

public:
    BankAccount()
    {
        accountNumber = "";
        customerName = "";
        balance = 0;

        depositCount = 0;
        withdrawalCount = 0;
        rejectedCount = 0;
    }

    // Create Account
    bool createAccount(string accNo, string name, double openingBalance)
    {
        if (accNo.length() != 10)
        {
            cout << "Error: Account number must have 10 digits." << endl;
            return false;
        }

        for (int i = 0; i < 10; i++)
        {
            if (accNo[i] < '0' || accNo[i] > '9')
            {
                cout << "Error: Account number must contain digits only." << endl;
                return false;
            }
        }

        if (openingBalance < 0)
        {
            cout << "Error: Negative opening balance not allowed." << endl;
            return false;
        }

        if (name == "")
        {
            cout << "Error: Name cannot be empty." << endl;
            return false;
        }

        accountNumber = accNo;
        customerName = name;
        balance = openingBalance;

        cout << "Account created successfully!" << endl;
        return true;
    }

    // Deposit
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            rejectedCount++;
            cout << "Invalid deposit amount." << endl;
        }
        else
        {
            balance = balance + amount;
            depositCount++;
            cout << "Deposit successful." << endl;
        }
    }

    // Withdraw
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            rejectedCount++;
            cout << "Negative or zero withdrawal not allowed." << endl;
        }
        else if (amount > balance)
        {
            rejectedCount++;
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance = balance - amount;
            withdrawalCount++;
            cout << "Withdrawal successful." << endl;
        }
    }

    // Check Balance
    void checkBalance()
    {
        cout << "Current Balance: Rs. " << balance << endl;
    }

    // Display Account
    void displayAccount()
    {
        cout << "\nAccount Details" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    // Transaction Summary
    void displayTransactionSummary()
    {
        cout << "\nTransaction Summary" << endl;
        cout << "Successful Deposits    : " << depositCount << endl;
        cout << "Successful Withdrawals : " << withdrawalCount << endl;
        cout << "Rejected Transactions  : " << rejectedCount << endl;
        cout << "Final Balance          : Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    bool accountCreated = false;

    int choice;
    string accNo, name;
    double amount, openingBalance;

    do
    {
        cout << "\n===== SecureBank Account Management System =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Balance Enquiry" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Display Transaction Summary" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (accountCreated)
            {
                cout << "Account already exists." << endl;
                break;
            }

            cout << "Enter Account Number (10 digits): ";
            cin >> accNo;

            cout << "Enter Customer Name (use _ instead of spaces): ";
            cin >> name;

            cout << "Enter Opening Balance: ";
            cin >> openingBalance;

            accountCreated = account.createAccount(accNo, name, openingBalance);
            break;

        case 2:
            if (!accountCreated)
            {
                cout << "Create an account first." << endl;
                break;
            }

            cout << "Enter Deposit Amount: ";
            cin >> amount;
            account.deposit(amount);
            break;

        case 3:
            if (!accountCreated)
            {
                cout << "Create an account first." << endl;
                break;
            }

            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;

        case 4:
            if (!accountCreated)
                cout << "Create an account first." << endl;
            else
                account.checkBalance();
            break;

        case 5:
            if (!accountCreated)
                cout << "Create an account first." << endl;
            else
                account.displayAccount();
            break;

        case 6:
            if (!accountCreated)
                cout << "Create an account first." << endl;
            else
                account.displayTransactionSummary();
            break;

        case 7:
            cout << "Thank you for using SecureBank!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}
