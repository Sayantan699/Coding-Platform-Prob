// User function Template for C++
class Solution
{
public:
    int removeConsecutiveSame(vector<string> &arr)
    {
        // Your code goes here
        stack<string> s;
        for (int i = 0; i < arr.size(); i++)
        {
            if (s.empty())
            {
                s.push(arr[i]);
            }
            else if (s.top() == arr[i])
            {
                s.pop();
            }
            else
                s.push(arr[i]);
        }
        return s.size();
    }
};

//Solution 2
// User function Template for C++
class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // Your code goes here
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(i==0)
                st.push(i);
            else{
                if(arr[st.top()] == arr[i]){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        return st.size();
    }
};