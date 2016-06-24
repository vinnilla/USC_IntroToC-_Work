//moneyaction.h
#ifndef MONEYACTION_H
#define MONEYACTION_H

#include "action.h"
#include "player.h"
#include <string>

using namespace std;

class MoneyAction : public Action {
private:
	int money;
public:
	MoneyAction();
	MoneyAction(string, int);
	void pay_money (Player&, int);
	void receive_money (Player&, int);
	void print();
	void executeAction();
};

#endif