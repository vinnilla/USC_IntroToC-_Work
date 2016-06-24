//moveaction.h
#ifndef MOVEACTION_H
#define MOVEACTION_H

#include "action.h"
#include <string>

using namespace std;

class MoveAction : public Action { 
private:
	int amount;
public:
	MoveAction();
	MoveAction(string, int);
	void set_amount(int);
	int get_amount();
	void print();
	void executeAction();
};

#endif