//servicechargechecking.h
#ifndef SERVICECHARGECHECKING_H
#define SERVICECHARGECHECKING_H

#include "checkingaccount.h"
#include <string>

class ServiceChargeChecking : public CheckingAccount {
private:
	int numberofChecks;
	int fee;
public:
	ServiceChargeChecking(int, string, int, char);
	void writeCheck(int);
};

#endif