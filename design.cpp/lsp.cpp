#include <bits/stdc++.h>
using namespace std;

class DepositAccount{
public:
    virtual void deposit(double amount) = 0;
};
class withdrawableAccount : public DepositAccount{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public withdrawableAccount{
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
class FixedAccount : public DepositAccount{
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

};

class BankClient {
private:
    vector<DepositAccount*> depositAccounts;
    vector<withdrawableAccount*> withdrawAccounts;

public:
    BankClient(vector<DepositAccount*> depositAccounts,
    vector<withdrawableAccount*> withdrawAccounts){
        this->withdrawAccounts = withdrawAccounts;
        this->depositAccounts = depositAccounts;
    }
    void processTransactions() {
        for (withdrawableAccount* acc : withdrawAccounts) {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for (DepositAccount* acc : depositAccounts) {
            acc->deposit(1000);
        }
    }
};
int main(){

    vector<DepositAccount*> depositAccounts;
    depositAccounts.push_back(new FixedAccount());
    vector<withdrawableAccount*> withdrawAccounts;
    withdrawAccounts.push_back(new SavingAccount());

    BankClient* client = new BankClient(depositAccounts,withdrawAccounts);
    client->processTransactions();

    return 0;
    
}