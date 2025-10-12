class Solution
{
public:
    vector<int> nextGreater(vector<int> &arr)
    {
        // code here
        // code here
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        int n = arr.size();
        for (int i = 0; i < 2*n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i%n])
            { // condition for the next greater element
                ans[st.top()] = arr[i%n];
                st.pop();
            }
            st.push(i%n); // pushing
        }
        return ans;
    }
};