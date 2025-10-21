class Solution {
  public:
  
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        queue<int> q;
        for(int i=0;i<k-1;i++){
            if(arr[i] < 0)
                q.push(i);
        }
        
        vector<int> ans;
        
        for(int i=k-1;i<n;i++){
            //Push the negative ele index
            if(arr[i] < 0)
                q.push(i);
                
            //Check if the index is coming in the current window size or not
            //if not pop from queue
            
            if(q.empty()) //if queue is empty simple print 0
                ans.push_back(0);
            else{
                if(q.front() <= i-k){ //Checking ind the current window size or not
                    q.pop();
                }
                if(q.empty()){
                    ans.push_back(0);
                }
                else
                    ans.push_back(arr[q.front()]);
            }
        }
        

    
    return ans;
        
    }
};