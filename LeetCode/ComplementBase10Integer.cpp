// Leet 1009. QCOmplement Base 10 Integer
//  The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its
//  binary representation.

// For example,
//     The integer 5 is "101" in binary and its complement is "010" which is the integer 2. Given an integer n,
//     return its complement.

//     Example 1 :

//     Input : n = 5 Output : 2 Explanation : 5 is "101" in binary,
//             with complement "010" in binary, which is 2 in base - 10.

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    if (n == 0)
    {
        cout << "Invalid number..";
        return 0;
    }
    int ans = 0, mul = 1;
    while (n > 0)
    {
        int rem = n % 2;
        rem = rem ^ 1; // bitwise xor to complement bits from 0 to 1 and vice versa..
        n /= 2;
        ans = ans + rem * mul;
        mul *= 2;
    }
    cout << "The commplement Base 10 Integer of " << n << " is: " << ans;
    return 0;
}