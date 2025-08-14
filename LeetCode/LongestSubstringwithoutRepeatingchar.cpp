// Longest substring without repeating characters

// Given a string s, find the length of the longest substring without duplicate characters.

//     Example 1 :

//     Input : s = "abcabcbb"
//     Output : 3 Explanation : The answer is "abc", with the length of 3.

// Sliding window method
#include <iostream>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;
    while (second < s.size())
    {
        while (count[s[second]]) // before increasing the size of the window checking if the character was already present on the substring or not
        {
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}

int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);
    cout << lengthOfLongestSubstring(str);
}