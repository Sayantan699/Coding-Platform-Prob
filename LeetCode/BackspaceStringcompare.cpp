class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> st2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        vector<char> s1;
        while (!st.empty())
        {
            s1.insert(s1.begin(), st.top());
            st.pop();
        }

        // for 2nd string
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (!st2.empty())
                    st2.pop();
            }
            else
                st2.push(t[i]);
        }
        vector<char> t1;
        while (!st2.empty())
        {
            t1.insert(t1.begin(), st2.top());
            st2.pop();
        }

        return s1 == t1;
    }
};