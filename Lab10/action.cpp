//action.cpp

#include "action.h"
#include <iostream>
#include <string>

using namespace std;

Action::Action() { }

Action::Action(string n) {
	name = n;
}

void Action::print_name() {
	cout << "Name of string: " << name;
}
/*
void Action::executeAction() {
	cout << "in action executeaction\n";
}
*/