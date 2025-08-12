// Sort Vowels in String
//  Given a 0-indexed string s, permute s to get a new string t such that:

// All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i]
// is a consonant, then t[i] = s[i].
// The vowels must be sorted in the nondecreasing order of their ASCII values.
// More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels,
// then t[i] must not have a higher ASCII value than t[j].
// Return the resulting string.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase.
// Consonants comprise all letters that are not vowels.

// Example 1:

// Input: s = "lEetcOde"
// Output: "lEOtcede"
// Explanation: 'E', 'O', and 'e' are the vowels in s;
// 'l', 't', 'c', and 'd' are all consonants.
// The vowels are sorted according to their ASCII values, and the consonants remain in the same places.

#include <iostream>
#include <vector>
using namespace std;

string sortvowel(string s)
{
    // two vector to count and store the no of occurence of vowel in correct postion
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            lower[s[i] - 'a']++;
            s[i] = '#';
        }

        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }

    string ans;
    // Storing Upper case vowel in string ans coz accn to ASCII Upper Case characters comes first
    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        while (upper[i])
        {
            ans += c;
            upper[i]--;
        }
    }

    // Storing Lower case vowel in string ans
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (lower[i])
        {
            ans += c;
            lower[i]--;
        }
    }

    // Now replace the '#' i.e vowels with the sorted vowels in ans
    int first = 0, second = 0;
    while (second < ans.size())
    {
        if (s[first] == '#')
        {
            s[first] = ans[second];
            second++;
        }
        first++;
    }

    return s;
}

int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);

    cout << sortvowel(str);
    return 0;
}