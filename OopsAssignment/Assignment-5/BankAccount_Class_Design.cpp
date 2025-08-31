// Design a class to represent a bank account. Which includes account number, name of the depositor, type of the account, balance amount in the account. Define Methods, to assign initial values, to Deposit an amount, to Withdraw amount after checking balance, to display name and balance
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    string accountType;
    double balance;

public:
    void assignValues(int accNo, string accName, string accType, double initialBalance) {
        accountNumber = accNo;
        name = accName;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully. New Balance: " << balance << endl;
        } 
        else {
            cout << "Invalid Deposit Amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance! Withdrawal Failed." << endl;
        } 
        else if (amount > 0) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully. New Balance: " << balance << endl;
        } 
        else {
            cout << "Invalid Withdrawal Amount!" << endl;
        }
    }

    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    int accNo;
    string accName, accType;
    double initialBalance, depositAmount, withdrawAmount;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cin.ignore(); 

    cout << "Enter Account Holder's Name: ";
    getline(cin, accName);

    cout << "Enter Account Type (Savings/Current): ";
    cin >> accType;

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    account.assignValues(accNo, accName, accType, initialBalance);

    cout << "\nEnter Amount to Deposit: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "\nEnter Amount to Withdraw: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    account.display();

    return 0;
}
