/*
13. In our country it is not possible to transfer money between two different banks.
You need to design a system by which transfers can be done between two different
banks(Such as DBBL and Trust Bank). For Simplicity, ignore the account number and
just think about balance. Transfer can happen in both directions, i.e., from DBBL to
Trust or from Trust to DBBL. This should be specified by user input.
a. Write down two classes that represents 2 different bank accounts such as
DBBL and Trust Bank (all the attributes will be private)
b. Each class will have 1 attribute -Balance
c. Write functions in each class to set and get the values.
d. In the main function you need to take the amount of money a user wants to
transfer.
e. Write one non-member function transferMoney(....) that will update the
Balance of each bank after each transfer.
f. Finally, show the current balance of each bank.
*/
#include <iostream>

using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount() {
        balance = 30000;
    }
    void setBalance(double b) {
        balance = b;
    }
    double getBalance() {
        return balance;
    }

};

void transferMoney(BankAccount& from, BankAccount& to, double amount) {
    if (from.getBalance() >= amount) {
        from.setBalance(from.getBalance() - amount);
        to.setBalance(to.getBalance() + amount);
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

int main() {
    BankAccount dbbl;
    BankAccount trust;

    double amount;

    cout << "Enter amount to transfer: ";
    cin >> amount;

    // transfer from dbbl to trust
    transferMoney(dbbl, trust, amount);

    // transfer from trust to dbbl
    transferMoney(trust, dbbl, amount);

    // print balances
    cout << "DBBL balance: " << dbbl.getBalance() << endl;
    cout << "Trust balance: " << trust.getBalance() << endl;

    return 0;
}
