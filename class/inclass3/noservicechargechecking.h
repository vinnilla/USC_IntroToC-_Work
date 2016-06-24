//noservicechargechecking.h
#ifndef NOSERVICECHARGECHECKING_H
#define NOSERVICECHARGECHECKING_H

#include "checkingaccount.h"
#include <string>

class NoServiceChargeChecking : public CheckingAccount {
private:
	int interest;

public:
	NoServiceChargeChecking(int, string, int, char);
	void monthEnd();
	void writeCheck(int);
};

#endif