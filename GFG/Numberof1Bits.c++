// Number of 1 Bits
//     Given a positive integer n.Your task is to return the count of set bits.

//     Examples :

//     Input : n = 6 Output : 2 Explanation : Binary representation is '110',
//             so the count of the set bit is 2.
#include <iostream>
using namespace std;

int Binary(int num)
{
    int res = 0, mul = 1;
    while (num > 0)
    {
        int rem = num % 2;
        res = rem * mul + res;
        num /= 2;
        mul *= 10;
    }
    return res;
}

int CountOneBit(int bin)
{
    int c = 0;
    while (bin > 0)
    {
        int rem = bin % 10;
        if (rem == 1)
            c++;
        bin /= 10;
    }
    return c;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int bin = Binary(num);

    cout << "The Binary Conversation of " << num << " is: " << bin;

    cout << endl;

    int countonebit = CountOneBit(bin);

    cout << "The Number of 1 Bit in " << num << " is: " << countonebit;
    return 0;
}