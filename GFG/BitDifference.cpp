// Bit Difference

//     You are given two numbers a and b.The task is to count the number of bits needed to be flipped to convert a to b.Note :
//     flipping of bit means inverting its value-- changing 1 to 0 and 0 to 1

//     Examples :

//     Input : a = 10,
//             b = 20 Output : 4 Explanation : a = 01010, b = 10100, As we can see, the bits of A that need to be flipped are 01010.
//             If we flip these bits, we get 10100, which is B.

#include <iostream>
using namespace std;

int flipbits(int a, int b)
{
    int c = 0;
    while (a > 0 || b > 0)
    {
        if ((a & 1) != (b & 1))
            c++;
        a >>= 1;
        b >>= 1;
    }
    return c;
}

int main()
{
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    cout << "The number of bits needed to be flipped to convert a to b: " << flipbits(a, b);
    return 0;
}