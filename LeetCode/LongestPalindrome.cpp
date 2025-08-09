// Longest palindrome
// Given a string s which consists of lowercase or uppercase letters,
// return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Example 1:

// Input : s = "abccccdd" Output : 7 Explanation : One longest palindrome that can be built is "dccaccd", whose length is 7.
#include <iostream>
#include <vector>
using namespace std;
int longestPalindrome(string s)
{
    vector<int> lower(26);
    vector<int> upper(26);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a')
        {
            lower[s[i] - 'a']++; // counting the number of lowercase characters
        }
        else
            upper[s[i] - 'A']++; // counting the number of uppercase characters
    }

    int odd = 0;
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        // lower
        if (lower[i] % 2 == 0)
            count += lower[i]; // adding if no of characters are even
        else
        {
            count += lower[i] - 1; // adding 1 less if no of characters are odd
            odd = 1;               // to store that odd number is present
        }

        // upper
        if (upper[i] % 2 == 0)
            count += upper[i];
        else
        {
            count += upper[i] - 1;
            odd = 1;
        }
    }
    return count + odd; // total length of the longest palindrome string possible
}

int main()
{

    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);

    cout << longestPalindrome(str);
}