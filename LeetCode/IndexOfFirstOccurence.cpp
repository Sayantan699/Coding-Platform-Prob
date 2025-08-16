#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i < n; i++)
    {
        int first = i, second = 0;
        while (second < m)
        {
            if (haystack[first] != needle[second])
                break;
            else
                first++, second++;
        }
        if (second == m)
            return first - second;
    }
    return -1;
}
int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);
    cout << strStr(str);
}