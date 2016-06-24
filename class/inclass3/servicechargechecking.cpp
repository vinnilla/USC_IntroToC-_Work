//servicechargechecking.cpp

#include "servicechargechecking.h"

using namespace std;

ServiceChargeChecking::ServiceChargeChecking(int num, string own, int bal, char type) : CheckingAccount() {
	number = num;
	owner = own;
	balance = bal;
	numberofChecks = 0;
	fee = 1;
}

void ServiceChargeChecking::writeCheck(int exchange) {
	numberofChecks++;
	if (numberofChecks > 5) {
		balance -= fee;
	}
	balance -= exchange;
}