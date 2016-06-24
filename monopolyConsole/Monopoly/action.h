// action.h
#ifndef ACTION_H
#define ACTION_H

#include <string>

using namespace std;

class Action {
private:
	string text[3];

public:
	void populate(string, string, string);
	void retrieve(string*);
};

#endif