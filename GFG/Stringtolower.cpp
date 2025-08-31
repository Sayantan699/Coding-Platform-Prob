class Solution
{
public:
    string toLower(string &s)
    {
        tolowerhelper(s, 0);
        return s;
    }

    void tolowerhelper(string &str, int ind)
    {
        int n = str.size();
        if (ind == n) // checking if beyond string length
            return;

        if (str[ind] >= 65 && str[ind] <= 90)
        {                   // uppercase
            str[ind] += 32; // convert to lowercase
        }

        tolowerhelper(str, ind + 1);
    }
};
