//highinterestsaving.h
#ifndef HIGHINTERESTSAVING_H
#define HIGHINTERESTSAVING_H

#include "savingsaccount.h"
#include <string>

class HighInterestSaving : public SavingsAccount {
private:
	int interest;
	int minimum;
public:
	HighInterestSaving(int, string, int, char);
	void monthEnd();
};

#endif