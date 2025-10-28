// 2444. Count Subarrays With Fixed Bounds
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
class Solution {
public:
    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        long long count = 0;
        int n = arr.size();
         int leftBound = -1;  // last index where element < minK or > maxK
        int lastMin = -1;    // last index where nums[i] == minK
        int lastMax = -1;   // last index where nums[i] == maxK
    for(int j=0;j<n;j++){
                // If current element index is not valid, update leftBound
                if(arr[j] < minK || arr[j] > maxK){
                    leftBound = j; //leftBound keeps track of the last invalid index
                }
                if(arr[j] == minK){
                    lastMin = j; // keeps track of the last minK found index
                }
                if(arr[j] == maxK){
                   lastMax = j; // keeps track of the last maxK found index
                }
            
            //count only if both minK and maxK seen after leftBound
            count += max(0,min(lastMin,lastMax)-leftBound); 
            
        }
        
    return count;
    }
};