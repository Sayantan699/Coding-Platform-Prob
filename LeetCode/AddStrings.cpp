// Add Strings

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
// You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string add(string num1, string num2)
{
    string ans;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int carry = 0, sum;
    while (index2 >= 0)
    {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index2--, index1--;
    }
    while (index1 >= 0)
    {
        int sum = num1[index1] - '0' + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
    }
    if (carry)
        ans += carry + '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

string addStrings(string num1, string num2)
{
    if (num1.size() < num2.size())
        return add(num2, num1);
    else
        return add(num1, num2);
}

int main()
{
    string str1, str2;
    cout << "Enter the String1: " << endl;
    getline(cin, str1);

    cout << "Enter the String2: " << endl;
    getline(cin, str2);

    cout << addStrings(str1, str2);
    return 0;
}