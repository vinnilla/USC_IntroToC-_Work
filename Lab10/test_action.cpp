//test_action.cpp

#include "action.h"
#include "moveaction.h"
#include "moneyaction.h"
#include "player.h"
#include "gotoaction.h"
#include <iostream>

using namespace std;

Player player1 (5000);
Player player2 (5000);

void executeAction(Action& a) {
	a.executeAction();
}

int main() {
	/*cout << "4.1\n";
	Action act("Hello there!");
	act.print_name();
	cout << endl;

	cout<<"4.2\n";
	MoveAction move ("Move!", 3);
	move.print();
	cout<<endl;
	int temp;
	temp = move.get_amount();
	cout << "Current amount of moves: " << temp << endl;
	int change = 5;
	cout << "Change amount of moves to: " << change << endl;
	move.set_amount(change);
	move.print();
	cout << endl;

	cout<<"4.3\n";
	player1.print_wealth();
	cout<<endl;
	MoneyAction money ("You must pay $4000!", 5000);
	money.print();
	cout<<endl;
	money.pay_money(player1, 4000);
	player1.print_wealth();
	cout<<endl;
	player1.give_money(4000);
	player2.get_money(4000);
	player2.print_wealth();
	cout<<endl;
	*/
	//Action a;
	MoneyAction ma1;
	MoveAction ma2;

	Action* actions[9];

	for (int i = 0; i < 9; i+=3) {
		actions[i] = new MoveAction();
		actions[i+1] = new MoneyAction();
		actions[i+2] = new GoToAction();
	}

	for (int i = 0; i < 9; i++) {
		actions[i]->executeAction();
	}



/*
	cout<<"Calling executeAction using objects\n";
	a.executeAction();
	ma1.executeAction();
	ma2.executeAction();

	cout <<"\nCalling executeAction in main\n";
	executeAction(a);
	executeAction(ma1);
	executeAction(ma2);
*/
	return 1;
}