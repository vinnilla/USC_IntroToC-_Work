//card,cpp

#include "card.h"
#include <iostream>

using namespace std;

void Card::populate(int Type, int pos, string Action1, string Action2) {
	action[0] = Action1;
	action[1] = Action2;
	position = pos;
	type = Type;
	return;
}

void Card::print() {
	if (type == 1) {
		cout << "Community Chest Card: " << action[0] << ". " << action[1] << endl;
	}
	else if (type == 2) {
		cout << "Chance Card: " << action[0] << ". " << action[1] << endl;	
	}
}