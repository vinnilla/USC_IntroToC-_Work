//highinterestsaving.cpp

#include "highinterestsaving.h"
#include <iostream>

using namespace std;

HighInterestSaving::HighInterestSaving(int num, string own, int bal, char type) : SavingsAccount(num, own, bal) {
	minimum = 1000;
	if (balance < minimum) {
		cout << "You cannot open a high interest savings account without a minimum starting balance of $1000." << endl;
		cout << "Your account has automatically become a normal savings account." << endl;
		interest = 1.01;
	}
	else {
		interest = 1.02;
	}
}

void HighInterestSaving::monthEnd() {
	balance *= interest;
}