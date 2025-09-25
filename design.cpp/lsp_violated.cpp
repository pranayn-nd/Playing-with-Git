#include <bits/stdc++.h>
using namespace std;

class Account{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amoutn) = 0;
};

class SavingAccount : public Account{
private:
    double balance;
public:
    SavingAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        balance +=amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount){
        if(amount> balance){
            cout << "Cannot withdraw : Insufficient balance savings" << endl;
            return;
        }
        balance = balance - amount;
        cout << "withdrawed from savings account" << endl;
    }
};
class FixedAccount : public Account{
private:
    double balance;
public:
    FixedAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        balance +=amount;
        cout << "Deposited: " << amount << " in Fixed Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount){
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }
    void processTransactions() {
        for (Account* acc : accounts) {
            acc->deposit(1000);
        try {
            acc->withdraw(500);
        } catch (const logic_error& e){
            cout << "Exception: " << e.what() << endl;
        }

        }
    }
};
int main(){

    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();

    return 0;
    
}