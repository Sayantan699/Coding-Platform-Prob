class Solution
{
public:
    vector<int> leftSmaller(vector<int> arr)
    {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            // While stack is not empty and current element is smaller than the element at st.top()
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i); // Push index
        }

        return ans;
    }
};