//action.cpp

#include "action.h"
#include <string>

using namespace std;

void Action::populate(string text1, string text2, string text3) {
	text[0] = text1;
	text[1] = text2;
	text[2] = text3;
	return;
}

void Action::retrieve(string Array[]) {
	Array[0] = text[0];
	Array[1] = text[1];
	Array[2] = text[2];
	return;
}