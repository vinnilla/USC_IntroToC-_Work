#include <iostream>
#include <cmath>

using namespace std;

// Declaration (function prototype for fact)
int fact(int);

int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
double x, sin;
  
  // Prompt the user
  cout << "Enter x in radians:  ";
  
  // get input
cin >> x;
cout << endl;

  // Do some operations
sin = x - (pow(x, 3.0)/fact(3)) + (pow(x, 5.0)/fact(5)) - (pow( x, 7.0)/fact(7));

  // Print the result to the user
cout << "The answer for sin(" << x << ") is " << sin << endl;
  
  // You're done
  return 0;
  
}


int fact(int n)
{
  int i;
  int result=1;
  for(i=1; i <= n; i++){
    result = result * i;
  }
  return result;
}

