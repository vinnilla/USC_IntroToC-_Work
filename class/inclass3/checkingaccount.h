//checkingaccount.h
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankaccount.h"

class CheckingAccount : public BankAccount {
public:
	virtual CheckingAccount();
	virtual void writeCheck(int);

};

#endif