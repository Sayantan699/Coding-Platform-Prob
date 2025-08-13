// // LEET Code 13
// // Roman to Integer

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II.
// The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
// Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.

#include <iostream>
using namespace std;
int romantoint(char c)
{

    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else
        return 1000; // for M
}
int roman(string s)
{
    int index = 0, sum = 0;
    while (index < s.size() - 1)
    {
        if (romantoint(s[index]) < romantoint(s[index + 1]))
        {
            sum -= romantoint(s[index]);
        }
        else
            sum += romantoint(s[index]);
        index++;
    }

    // for the last roman character
    sum += romantoint(s[s.size() - 1]);
    return sum;
}
int main()
{
    string str;
    cout << "Enter the Roman String: " << endl;
    getline(cin, str);
    cout << roman(str);
}