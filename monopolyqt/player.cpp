//player.cpp
#include "player.h"

Player::Player(int number) {
  playerName = "Player " + QString::number(number);
  playerMoney = 400000;
  currentSpace = 0;
  jail = false;
  jailcounter = 0;
}

void Player::setName( QString n ) {
  playerName = n;
}

QString Player::getName() {
  return playerName;
}

int Player::getMoney() {
  return playerMoney;
}

void Player::payMoney(int cost) {
	playerMoney -= cost;
}

void Player::getMoney(int payment) {
	playerMoney += payment;
}

bool Player::setCurrentSpace(int moves) {
	int previous = currentSpace;
	currentSpace = (currentSpace + moves)%40;
	//check to see if go was passed
	if (previous > currentSpace) {
		return true;
	}
	else {
		return false;
	}
}

void Player::movetoSpace(int newSpace) {
	currentSpace = newSpace;
}

int Player::getCurrentSpace() {
	return currentSpace;
}

void Player::setJail(bool status) {
	jail = status;
}

bool Player::retrieveJail() {
	return jail;
}

void Player::incrementJailCounter() {
	jailcounter++;
}

void Player::setJailCounter(int change) {
	jailcounter = change;
}

int Player::retrieveJCounter() {
	return jailcounter;
}