// Number of 1 Bits
//     Given a positive integer n.Your task is to return the count of set bits.

//     Examples :

//     Input : n = 6 Output : 2 Explanation : Binary representation is '110',
//             so the count of the set bit is 2.
#include <iostream>
using namespace std;

int CountOneBit(int num) // Effective method using bitwise operation
{
    int c = 0;
    while (num > 0)
    {
        c += (num & 1); // add 1 if last bit is 1 e
        num >>= 1;      // right shifting
    }
    return c;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int countonebit = CountOneBit(num);

    cout << "The Number of 1 Bit in " << num << " is: " << countonebit;
    return 0;
}