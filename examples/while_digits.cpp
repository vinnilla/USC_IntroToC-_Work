#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
int num, digits, integer, counter;

cout << "Enter an integer between 0 and 999: ";
cin >> num;
cout << endl;

digits = ceil(log10(num));

while (digits >= 1)
{
integer = pow (10, digits-1);
cout << integer << "'s digit is " << int(num/integer) << endl;
num -= int(num/integer)*integer;
digits --;
}

return 0;

}
