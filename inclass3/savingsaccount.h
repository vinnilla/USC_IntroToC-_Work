//savingsaccount.h
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "bankaccount.h"
#include <string>

class SavingsAccount : public BankAccount {
private:
	int interest;
public:
	SavingsAccount(int, string, int, char);
	void monthEnd();
};

#endif