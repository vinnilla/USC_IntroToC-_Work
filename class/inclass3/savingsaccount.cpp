//savingsaccount.cpp

#include "savingsaccount.cpp"

using namespace std;

SavingsAccount::SavingsAccount(int num, string own, int bal, char type) : BankAccount() {
	number = num;
	owner = own;
	balance = bal;
	interest = 1.01;
}

void SavingsAccount::monthEnd() {
	balance *= interest;
}