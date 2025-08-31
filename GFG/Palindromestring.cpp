class Solution
{
public:
    bool isPalindrome(string &s)
    {
        // code here
        int n = s.size();
        if (ispalhelper(s, 0, n - 1))
            return true;
        return false;
    }
    bool ispalhelper(string &str, int start, int end)
    {
        if (start >= end)
            return true;

        if (str[start] != str[end])
            return false;
        return ispalhelper(str, start + 1, end - 1);
    }
};
