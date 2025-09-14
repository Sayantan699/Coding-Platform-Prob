// User function template for C++
class Solution
{
public:
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        vector<string> ans;
        string temp;
        solve(n, ans, temp, 0, 0);
        return ans;
    }

    void solve(int n, vector<string> &ans, string &temp, int zero, int one)
    {
        if (temp.size() == n)
        { // when the size of temp is equal to max size of bit
            ans.push_back(temp);
            return;
        }

        // Added 1 first coz the accn to ques output should be in desc order
        temp.push_back('1');
        solve(n, ans, temp, zero, one + 1);
        temp.pop_back(); // backtracking

        if (zero < one)
        {
            temp.push_back('0');
            solve(n, ans, temp, zero + 1, one);
            temp.pop_back(); // backtracking
        }
    }
};