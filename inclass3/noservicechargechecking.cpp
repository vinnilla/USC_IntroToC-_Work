//noservicechargechecking.cpp

#include <noservicechargechecking.h>

using namespace std;

NoServiceChargeChecking::NoServiceChargeChecking(int num, string own, int bal, char type) : CheckingAccount() {
	number = num;
	owner = own;
	balance = bal;
	interest = 1.01;
}

void NoServiceChargeChecking::monthEnd() {
	balance *= interest;
}

void NoServiceChargeChecking::writeCheck(int exchange) {
	balance -= exchange;
}