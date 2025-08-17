class Solution
{
public:
    // Build LPS array for string b
    vector<int> buildLPS(string &pat)
    {
        int m = pat.size();
        vector<int> lps(m, 0);
        int pre = 0, suf = 1;

        while (suf < m)
        {
            if (pat[pre] == pat[suf])
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
        return lps;
    }

    // KMP match function
    bool KMP_MATCH(string &text, string &pat)
    {
        vector<int> lps = buildLPS(pat);
        int i = 0, j = 0;
        int n = text.size(), m = pat.size();

        while (i < n)
        {
            if (text[i] == pat[j])
            {
                i++, j++;
                if (j == m)
                    return true; // match found
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;

        string temp = a;
        int repeat = 1;

        // repeat until temp is at least length of b
        while (temp.size() < b.size())
        {
            temp += a;
            repeat++;
        }

        // first check with current temp
        if (KMP_MATCH(temp, b))
            return repeat;

        // check with one more repetition
        temp += a;
        if (KMP_MATCH(temp, b))
            return repeat + 1;

        return -1;
    }
};
