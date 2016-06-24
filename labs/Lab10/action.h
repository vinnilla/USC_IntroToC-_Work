//action.h
#ifndef ACTION_H
#define ACTION_H

#include <string>

using namespace std;

class Action {
private:
	string name;
public:
	Action ();
	Action (string);
	void print_name();
	virtual void executeAction() = 0;
};

#endif
