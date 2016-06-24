//bankaccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
protected:
	int number;
	string owner;
	int balance;

public:
	virtual BankAccount();
	virtual BankAccount(int, string, int);
	int retrieveNumber();
	string retrieveOwner();
	int retrieveBalance();
	void deposit(int);
	void withdraw(int);
	virtual void monthEnd();

};


#endif