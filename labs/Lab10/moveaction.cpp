//moveaction.cpp

#include "moveaction.h"
#include "action.h"
#include <string>
#include <iostream>

using namespace std;

MoveAction::MoveAction() { }

MoveAction::MoveAction(string n, int amt) : Action(n) {
	amount = amt;
}

void MoveAction::set_amount(int amt) {
	amount = amt;
}

int MoveAction::get_amount() {
	return amount;
}

void MoveAction::print() {
	Action::print_name();
	cout << "  Amount: " << amount;	
}

void MoveAction::executeAction() {
	cout << "in moveaction executeaction\n";
}