class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        stack<int> s; //to store only the bigger elements
       
       
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            
            while(!s.empty() && s.top() < temp){
                st.push(s.top());
                s.pop();
            }
            
            s.push(temp);
                
        }
        
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
    }
};
