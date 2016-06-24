#include <iostream>

using namespace std;

int rFib(int num1, int num2, int numTerms){
	//base case
	if (numTerms == 1) {
		return num1;
	}
	if (numTerms == 2) {
		return num2;
	}

	//recursive case
	return rFib(num1, num2, numTerms-1) + rFib(num1, num2, numTerms-2);
}

int main() {
	cout << rFib(1,1,100) << endl;

	return 0;
}