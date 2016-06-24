//bankaccount.cpp

#include "bankaccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount() {}

BankAccount::BankAccount(int num, string own, int bal) {
	number = num;
	owner = own;
	balance = bal;
}

int BankAccount::retrieveNumber() {
	return number;
}

string BankAccount::retrieveOwner() {
	return owner;
}

int BankAccount::retrieveBalance() {
	return balance;
}

void BankAccount::deposit(int money) {
	balance += money;
}

void BankAccount::withdraw(int money) {
	if (money < balance) {
		balance -= money;
	}
	else {
		cout << "You cannot withdraw more than you have." << endl;
	}
}

void BankAccount::monthEnd() {}