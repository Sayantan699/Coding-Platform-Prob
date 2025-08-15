// Longest Prefix Suffix
// Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
// Note : Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input : s = "abab" Output : 2 Explanation : The string "ab" is the longest prefix and suffix.

// Apporach - KMP Method

/*
Explanation -
1.The KMP Algorithmis a string pattern matching algorithm that efficiently finds all occurrences of a pattern in
a given text.It uses method of creating an LPS array for the pattern which tells us how many characters can be skipped
 when a mismatch happens....
2.Here we use KMP method to solve the problem within O(n) Time complexity
3.when the prefix character = suffix character we increase the size of the current substring(prefix = suffix) by prefix+1...
and incrementing prefix and suffix ;
4.when characters mismatch , we have 2 condition when the prefix is pointing on the first index and when its not pointing in the first index
5.when prefix is pointing in the first index its of no use to go backwards to find matching characters as there are not characters i.e we assign the suffix to 0
6.when prefix is not pointing in the first index we point prefix to the index which is the "value assign of the previous element of prefix"
7.after traversing to the end of the text we return the last value assigned
*/
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