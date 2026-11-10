// SecureBank Account Management System
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string customerName;
    double balance;

    int depositCount;
    int withdrawalCount;
    int rejectedCount;

public:
    BankAccount()
    {
        accountNumber = 0;
        customerName = "";
        balance = 0.0;

        depositCount = 0;
        withdrawalCount = 0;
        rejectedCount = 0;
    }

    void createAccount(int accNo, string name, double openingBalance)
    {
        accountNumber = accNo;
        customerName = name;

        if (openingBalance < 0)
        {
            cout << "Error: Opening balance cannot be negative." << endl;
            balance = 0;
        }
        else
        {
            balance = openingBalance;
            cout << "Account created successfully." << endl;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            depositCount++;
            cout << "Deposit successful." << endl;
        }
        else
        {
            rejectedCount++;
            cout << "Error: Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            rejectedCount++;
            cout << "Error: Invalid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            rejectedCount++;
            cout << "Error: Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
            withdrawalCount++;
            cout << "Withdrawal successful." << endl;
        }
    }

    void checkBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    void displayAccount()
    {
        cout << "\nAccount Details" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    void displayTransactionSummary()
    {
        cout << "\nTransaction Summary" << endl;
        cout << "Successful Deposits    : " << depositCount << endl;
        cout << "Successful Withdrawals : " << withdrawalCount << endl;
        cout << "Rejected Transactions  : " << rejectedCount << endl;
        cout << "Final Balance           : " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    bool accountCreated = false;

    int choice;
    int accNo;
    string name;
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

            cout << "Enter Account Number: ";
            cin >> accNo;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Opening Balance: ";
            cin >> openingBalance;

            account.createAccount(accNo, name, openingBalance);
            accountCreated = true;
            break;

        case 2:
            if (!accountCreated)
            {
                cout << "Please create an account first." << endl;
                break;
            }

            cout << "Enter Deposit Amount: ";
            cin >> amount;
            account.deposit(amount);
            break;

        case 3:
            if (!accountCreated)
            {
                cout << "Please create an account first." << endl;
                break;
            }

            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;

        case 4:
            if (!accountCreated)
            {
                cout << "Please create an account first." << endl;
                break;
            }

            account.checkBalance();
            break;

        case 5:
            if (!accountCreated)
            {
                cout << "Please create an account first." << endl;
                break;
            }

            account.displayAccount();
            break;

        case 6:
            if (!accountCreated)
            {
                cout << "Please create an account first." << endl;
                break;
            }

            account.displayTransactionSummary();
            break;

        case 7:
            cout << "Thank you for using SecureBank." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
