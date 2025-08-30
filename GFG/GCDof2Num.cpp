// // GCD of two numbers

// Given two positive integers a and b, find GCD of a and b.

//     Note : Don't use the inbuilt gcd function

//     Examples :

//     Input : a = 20, b = 28 Output : 4 Explanation : GCD of 20 and 28 is 4

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return abs(a);
    }
    int r = a % b;
    return gcd(b, r);
}
int main()
{

    int n1, n2;

    cout << "Enter the value of n1: ";
    cin >> n1;

    cout << "Enter the value of n2: ";
    cin >> n2;

    cout << "The GCD of " << n1 << " and " << n2 << " is: " << gcd(n1, n2);

    return 0;
}