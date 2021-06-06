#include<iostream>
#include <string>

using namespace std;

class bankaccount {
private:
  string name_of_customer, account_type;
  int account_number, balance_amount;
public:
  bankaccount () : balance_amount(0) {}
  void customerDetails(string name, int num) {
    name_of_customer = name;
    account_number = num;
  }

  void accountType(string _type) {
    account_type = _type;
  }

  void balance() {
    cout << "Balance : " << balance_amount << "\n";
  }

  void deposit(int add) {
    balance_amount += add;
    balance();
  }

  void withdraw(int sub) {
    if (sub > balance_amount) {
      cout << "ERROR : NOT ENOUGH BALANCE !" << "\n";
    } else {
      balance_amount -= sub;
    }
  }

  void display() {
    cout << "NAME : " << name_of_customer << "\n";
    cout << "ACCOUNT NUMBER : " << account_number << "\n";
    cout << "ACCOUNT TYPE : " << account_type << "\n";
    cout << "ACCOUNT BALANCE : " << balance_amount << "\n"; 
  }  
};

int main() {
  bankaccount x;
  x.customerDetails("farzana", 100);
  x.accountType("Current");
  x.deposit(500);
  x.withdraw(2000);
  x.withdraw(100);
  x.balance();
  x.display();
}