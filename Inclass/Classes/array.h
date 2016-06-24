// array.h
#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	int* arr;
	int arrsize;

public:
	Array();
	Array(int);
	~Array();
	int find_largest();
	int find_smallest();
};

#endif