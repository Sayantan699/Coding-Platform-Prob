// Power of 4

// Given an integer n, return true if it is a power of four.Otherwise, return false.

//     An integer n is a power of four,
//     if there exists an integer x such that n == 4x.

//         Example 1 :

//     Input : n = 16 Output : true
#include <iostream>
using namespace std;

bool isPowerOfFour(int n)
{

    if (n == 1) // 4^0 = 1
        return true;
    if (n == 0 || n % 4 != 0) // i.e not divisible by 4 i.e cant be its power
        return false;

    return isPowerOfFour(n / 4); // decreasing the value by 4
}
int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if (isPowerOfFour(n))
        cout << n << " is power of 4";
    else
        cout << n << " is not power of 4";

    return 0;
}