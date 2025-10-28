class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> q;
        int flip = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front() < i)
                q.pop_front();
            if(q.size()%2 == nums[i]){ // 0 == 0 or vice versa flip it
            if(i+k-1>=n) // exceeding window size
                return -1;
            q.push_back(i+k-1); //pushing the last index of window size k
            flip++;
            }
        }
        return flip;
    }
};