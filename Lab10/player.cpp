//player.cpp

#include "player.h"
#include <iostream>

using namespace std;

Player::Player() { }

Player::Player(int money) {
	wealth = money;
}

void Player::give_money (int money) {
	wealth -= money;
}

void Player::get_money (int money) {
	wealth += money;
}

void Player::print_wealth () {
	cout << "Wealth: " << wealth;
}