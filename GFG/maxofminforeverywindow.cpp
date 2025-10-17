class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){ //Next smallest right
                int ind = st.top();
                st.pop(); //st.top() contains the next smallest left
                int range;
                if(st.empty()){
                    range = i;
                }
                else{
                 range = i - st.top() - 1; //maximum window size
                }
                ans[range-1] = max(ans[range-1],arr[ind]);
            }
            st.push(i);
            
        }
        while(!st.empty()){
            int ind = st.top();
                st.pop(); //st.top() contains the next smallest left
                int range;
                if(st.empty()){
                    range = n;
                }
                else{
                 range = n - st.top() - 1; //maximum window size
                }
                ans[range-1] = max(ans[range-1],arr[ind]);
        }
        
        
        //for unitialized
        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        
        return ans;
    }
};