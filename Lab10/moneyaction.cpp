//moneyaction.cpp

#include "moneyaction.h"
#include "action.h"
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

MoneyAction::MoneyAction() { }

MoneyAction::MoneyAction(string n, int mny) : Action(n) {
	money = mny;
}

void MoneyAction::pay_money(Player& p, int amount) {
	p.give_money(amount);
	money -= amount;
}

void MoneyAction::receive_money(Player& p, int amount) {
	p.get_money(amount);
	money += amount;
}

void MoneyAction::print() {
	Action::print_name();
	cout << "  Money: " << money;
}

void MoneyAction::executeAction() {
	cout << "in moneyaction executeaction\n";
}