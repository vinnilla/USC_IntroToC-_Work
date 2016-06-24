//space.cpp

#include "space.h"

Space::Space() {
	buyable = false;
	upgradable = false;
	owner = -1;
}

void Space::setupinfo(int Buy, int Rent, int Group, int upPrice) {
	buyPrice = Buy;
	rentPrice = Rent;
	updatedRent = Rent;
	group = Group;
	upgradePrice = upPrice;
	upgrade = 0;
	owner = -1;
	monopoly = false;
	buyable = true;
}

void Space::setType(int Type) {
	type = Type;

	if (Type = 0) {
		upgradable = true;
	}
}

void Space::setX(int coords) {
	x = coords;
}

void Space::setY(int coords) {
	y = coords;
}

void Space::setOwner(int player) {
	owner = player;
	buyable = false;
}

int Space::retrieveX() {
	return x;
}

int Space::retrieveY() {
	return y;
}

int Space::retrieveType() {
	return type;
}

int Space::retrieveBuy() {
	return buyPrice;
}

int Space::retrieveRent() {
	return updatedRent;
}

int Space::retrieveOwner() {
	return owner;
}

int Space::retrieveUpgrade() {
	return upgrade;
}

int Space::retrieveUpgradePrice() {
	return upgradePrice;
}

int Space::retrieveGroup() {
	return group;
}

bool Space::checkMonopoly() {
	return monopoly;
}

bool Space::checkBuyable() {
	return buyable;
}

void Space::upgradesingle() {
	if (upgrade == 0) {
		updatedRent *= 2.5;
		upgrade++;
	}

	else if (upgrade == 1) {
		updatedRent *= 3;
		upgrade++;
	}

	else if (upgrade == 2) {
		updatedRent *= 2.3;
		upgrade++;
	}

	else if (upgrade == 3) {
		updatedRent *= 1.4;
		upgrade++;
	}

	else if (upgrade == 4) {
		updatedRent *= 1.2;
		upgrade++;
	}
}

void Space::updateMonopoly(int number) {
	int temp = rentPrice;
	for (int i = 0; i < number; i++) {
		rentPrice *= 2;	
	}
	updatedRent = rentPrice;
	rentPrice = temp;
	monopoly = true;
}