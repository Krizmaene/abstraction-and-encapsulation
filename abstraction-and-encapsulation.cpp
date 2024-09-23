#include <iostream>
using namespace std;

class Account {
protected: 
    double balance;

public: 
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void checkBalance() const = 0;
};

class SavingsAccount : public Account {
private: 
    const double MIN_BALANCE = 1000.0;

public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {
        if (initialBalance < MIN_BALANCE){
            cout << "Initial balance for savings account must be at least " << MIN_BALANCE << "." << endl;
            balance = MIN_BALANCE;
        }
    }

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "\nInvalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= MIN_BALANCE) {
            balance -= amount;
            cout << "\nWithdrawal successful." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "\nInsufficient balance or invalid withdrawal amount." << endl;
            cout << "Minimun balance must be " << MIN_BALANCE << "." << endl; 
        }
    }

    void checkBalance() const override {
        cout << "\nSaving Account Balance: " << balance << endl;
    }
};

class CurrentAccount: public Account {
public: 
    CurrentAccount(double initialBalance) : Account(initialBalance) {}

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "\nInvalide deposit amount." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nWithdrawal successful." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "\nInsufficient balance or invalid withdrawal amount." << endl;
        }
    }

    void checkBalance() const override {
        cout << "\nCurrent Account Balance: " << balance << endl;
    }
 };

 void mainMenu() {
    cout << "Main Menu" << endl;
    cout << "1 - Savings Account" << endl;
    cout << "2 - Current Account" << endl;
    cout << "3 - Exit" << endl;
 }

 void subMenu() {
    cout << "\nSub Menu" << endl;
    cout << "1 - Deposit" << endl;
    cout << "2 - Withdraw" << endl;
    cout << "3 - Check Balance" << endl;
    cout << "4 - Back" << endl;
 }

 void handleSavingsAccount(SavingsAccount& account) {
    int choice;
    do {
        subMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1: 
                cout << "\nEnter deposit amoount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2: 
                cout << "\nEnter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4: 
                cout << "\nGoing back to Main Menu..." << endl;
                break;
            default:
                cout << "\nInvalid input. Try again." << endl;
                break;
        }
    } while (choice != 4);
 }

 void handleCurrentAccount(CurrentAccount& account) {
    int choice; 
    do {
        subMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "\nEnter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2: 
                cout << "\nEnter withdrawal account: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "\nGoing back to Main Menu..." << endl;
                break;
            default:
                cout << "\nInvalid input. Try again." << endl;
                break;
        }
    } while (choice != 4);
 }

 int main() {
    int mainChoice;
    double initialBalance;

    do {
        mainMenu();
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: 
                cout << "\nEnter initial balance for Savings Account: " ;
                cin >> initialBalance;
                {
                    SavingsAccount savingsAccount(initialBalance);
                    handleSavingsAccount(savingsAccount);
                }
                break;
            case 2:
                cout << "\nEnter initial balance for Current Account: ";
                cin >> initialBalance;
                {
                    CurrentAccount currentAccount(initialBalance);
                    handleCurrentAccount(currentAccount);
                }
                break;
            case 3: 
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nInvalid input. Try Again." << endl;
                break;
        }
    } while (mainChoice != 3);

    return 0;
 }