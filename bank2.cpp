
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
                cout << "Error: Digits only allowed." << endl;
                return false;
            }
        }

        if (openingBalance < 0 || name == "")
        {
            cout << "Invalid account details." << endl;
            return false;
        }

        accountNumber = accNo;
        customerName = name;
        balance = openingBalance;

        cout << "Account created successfully!" << endl;
        return true;
    }

    string getAccountNumber()
    {
        return accountNumber;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            rejectedCount++;
            cout << "Invalid deposit amount." << endl;
        }
        else
        {
            balance += amount;
            depositCount++;
            cout << "Deposit successful." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            rejectedCount++;
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            rejectedCount++;
            cout << "Insufficient balance." << endl;
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
        cout << "Current Balance: Rs. " << balance << endl;
    }

    void displayAccount()
    {
        cout << "\nAccount Details" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    void displayTransactionSummary()
    {
        cout << "\nTransaction Summary" << endl;
        cout << "Successful Deposits    : " << depositCount << endl;
        cout << "Successful Withdrawals : " << withdrawalCount << endl;
        cout << "Rejected Transactions  : " << rejectedCount << endl;
        cout << "Final Balance          : Rs. " << balance << endl;
    }
};

// Find Account
int findAccount(BankAccount accounts[], int count, string accNo)
{
    for (int i = 0; i < count; i++)
    {
        if (accounts[i].getAccountNumber() == accNo)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    BankAccount accounts[100];
    int accountCount = 0;

    int choice, index;
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
        cout << "7. Display All Accounts" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (accountCount == 100)
            {
                cout << "Maximum account limit reached." << endl;
                break;
            }

            cout << "Enter Account Number (10 digits): ";
            cin >> accNo;

            if (findAccount(accounts, accountCount, accNo) != -1)
            {
                cout << "Account number already exists." << endl;
                break;
            }

            cout << "Enter Customer Name (use _ instead of spaces): ";
            cin >> name;

            cout << "Enter Opening Balance: ";
            cin >> openingBalance;

            if (accounts[accountCount].createAccount(accNo, name, openingBalance))
            {
                accountCount++;
            }
            break;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            cout << "Enter Account Number: ";
            cin >> accNo;

            index = findAccount(accounts, accountCount, accNo);

            if (index == -1)
            {
                cout << "Account not found." << endl;
                break;
            }

            if (choice == 2)
            {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                accounts[index].deposit(amount);
            }
            else if (choice == 3)
            {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                accounts[index].withdraw(amount);
            }
            else if (choice == 4)
            {
                accounts[index].checkBalance();
            }
            else if (choice == 5)
            {
                accounts[index].displayAccount();
            }
            else if (choice == 6)
            {
                accounts[index].displayTransactionSummary();
            }
            break;

        case 7:
            if (accountCount == 0)
            {
                cout << "No accounts available." << endl;
            }
            else
            {
                cout << "\n===== All Bank Accounts =====" << endl;

                for (int i = 0; i < accountCount; i++)
                {
                    accounts[i].displayAccount();
                }
            }
            break;

        case 8:
            cout << "Thank you for using SecureBank!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}
