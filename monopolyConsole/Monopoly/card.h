//card.h
#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
private:
	string action[2];
	int type; // 1=community chest, 2=chance
	int position;

public:
	void populate(int, int, string, string);
	void print();

};

#endif