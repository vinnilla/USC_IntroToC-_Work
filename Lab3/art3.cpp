#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double angle = 0;
	cout << "Enter an angle within 15 and 75 degrees: ";
	cin >> angle;
	cout << endl;
	angle /= 57.2957795; //convert degrees to radians

	for (int r=1; r<31; r++) {
		int stars = floor(r*tan(angle));
		for (int i = 0; i<stars; i++) {
			if (stars >= 20 and stars <= 30) {
				cout << "********************";
				break;
			} //end of if
			else {
			cout << "*";
			} //end of else
		} //end of nested for
	cout << endl;
	} //end of for
} //end of main
