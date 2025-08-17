// Min Chars to Add for Palindrome
// Difficulty: HardAccuracy: 46.79%Submissions: 97K+Points: 8Average Time: 25m
// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Note: A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples:

// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of the above string to make it palindrome: "cbabc"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minChar(string &s)
{
    // code here
    int size = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    s += '$';
    s += rev;

    // Here we have taken the size of the LPS array as 2 * size + 1 as it contains the size of the original array and the reverse
    // array with the additional symbol

    vector<int> lps(2 * size + 1, 0);
    int pre = 0, suf = 1;
    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++, suf++;
        }
        else
        {
            if (pre == 0)
            {
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }

    return size - lps[s.size() - 1];
}

int main()
{

    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);
    cout << minChar(str);
    return 0;
}