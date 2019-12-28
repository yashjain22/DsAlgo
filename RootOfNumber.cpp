#include <iostream>
#include <math.h>
using namespace std;

/*
Find the nth root of a number,
well this problem seems trivial
but knowing some math functions and implementing from scratch gives you breif idea
about how computational numerical analysis works. 
similiarly this problem can also be extended to nth power of a number.
*/
double binary_search(double x,unsigned int n)
{
  double low = 0;
  double high = x;
  while(low <= high)
  {
    double mid = low + (high-low)/2;
    double temp = pow(mid,n) - x;
    if(temp >= (double)-0.001 && temp <= (double)0.001)
    {
      return mid;
    }
    if(temp > 0 )
    {
      high = mid;
    }
    else
    {
      low = mid;
    }
  }
  return -1;
}
double root(double x, unsigned int n) 
{
  return binary_search(x,n);
}

int main() {
  cout << root(1600,7) << endl;
  return 0;
}
