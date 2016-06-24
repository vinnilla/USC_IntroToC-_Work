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
		for (int i = 0; i<floor(r*tan(angle)); i++) {
			cout << "*";
		} //end of nested for
	cout << endl;
	} //end of for
} //end of main
