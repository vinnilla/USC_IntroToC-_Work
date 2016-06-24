// player.h
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
private:
	int wealth;
public:
	Player();
	Player(int);
	void give_money(int);
	void get_money(int);
	void print_wealth();
};

#endif