class Solution
{
public:
    vector<int> nextGreater(vector<int> &arr)
    {
        // code here
        // code here
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            { // condition for the next greater element
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i); // pushing
        }
        return ans;
    }
};