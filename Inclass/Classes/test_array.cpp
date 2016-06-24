// test_array.cpp

#include "array.h"
#include <iostream>

using namespace std;

int main() {
	Array myArray1(20);
	Array myArray2;

	cout << "Largest1: " << myArray1.find_largest() << "\nSmallest1: " << myArray1.find_smallest() << endl;
	cout << "Largest2: " << myArray2.find_largest() << "\nSmallest2: " << myArray2.find_smallest() << endl;

	return 0;
}