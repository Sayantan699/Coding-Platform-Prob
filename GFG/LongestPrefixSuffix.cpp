// Longest Prefix Suffix
// Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
// Note : Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input : s = "abab" Output : 2 Explanation : The string "ab" is the longest prefix and suffix.

// Apporach - KMP Method
#include <iostream>
#include <vector>
using namespace std;
int getLPSLength(string &s)
{
    // code here
    vector<int> lps(s.size(), 0);
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
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return lps[s.size() - 1];
}
int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);
    cout << getLPSLength(str);
}