// array.cpp

#include "array.h"
#include <iostream>

using namespace std;

Array::Array() {
	cout << "In the default constructor\n";
	arrsize = 10;
	arr = new int[arrsize];

	for (int i = 0; i<10; i++) {
		arr[i] = i;
	}

}

Array::Array(int size) {
	cout << "In the other constructor\n";
	arrsize = size;
	arr = new int(size);

	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

Array::~Array() {
	cout << "In the destructor\n";
	delete [] arr;

}

int Array::find_largest() {
	int largest = arr[0];

	for (int i = 1; i < arrsize; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}

	return largest;
}

int Array::find_smallest() {
	int smallest = arr[0];

	for (int i = 1; i < arrsize; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
		}
	}

	return smallest;
}