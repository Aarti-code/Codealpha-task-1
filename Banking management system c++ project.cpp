
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
    string name;
    int accountNumber;
    float balance;

    Account(string name, int accountNumber) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = 0.0;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: $" << amount << "\n";
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
    }

    void checkBalance() {
        cout << "Balance: $" << balance << "\n";
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        string name;
        int accountNumber;

        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accountNumber;

        accounts.emplace_back(name, accountNumber);
        cout << "Account created successfully!\n";
    }

    Account* findAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void depositMoney() {
        int accountNumber;
        float amount;

        cout << "Enter account number: ";
        cin >> accountNumber;
        Account* account = findAccount(accountNumber);

        if (account) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void withdrawMoney() {
        int accountNumber;
        float amount;

        cout << "Enter account number: ";
        cin >> accountNumber;
        Account* account = findAccount(accountNumber);

        if (account) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void checkAccountBalance() {
        int accountNumber;

        cout << "Enter account number: ";
        cin >> accountNumber;
        Account* account = findAccount(accountNumber);

        if (account) {
            account->checkBalance();
        } else {
            cout << "Account not found!\n";
        }
    }
};

int main() {
    BankingSystem bankingSystem;
    int choice;

    do {
        cout << "\n--- Banking Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bankingSystem.createAccount();
                break;
            case 2:
                bankingSystem.depositMoney();
                break;
            case 3:
                bankingSystem.withdrawMoney();
                break;
            case 4:
                bankingSystem.checkAccountBalance();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
    