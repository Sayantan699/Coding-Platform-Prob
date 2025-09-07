// // Subset
// Given an integer array nums of unique elements, return all possible subsets(the power set).

// The solution set must not contain duplicate subsets.Return the solution in any order.

//     Example 1 :

//     Input : nums = [ 1, 2, 3 ] Output : [ [], [1], [2], [ 1, 2 ], [3], [ 1, 3 ], [ 2, 3 ], [ 1, 2, 3 ] ] Example 2 :

//     Input : nums = [0] Output : [ [], [0] ]

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans; // main 2d array
        vector<int> temp;        // 1d array which will contain the subset elements

        int n = nums.size();
        subsethelper(nums, 0, n, ans, temp);
        return ans;
    }
    void subsethelper(vector<int> &nums, int ind, int N, vector<vector<int>> &ans, vector<int> temp)
    {
        // Base case when ind == length of the vector
        if (ind == N)
        {
            // add the 1d vector in the main 2d vector
            ans.push_back(temp);
            return;
        }
        // when ele will not be added in the sub-vector
        subsethelper(nums, ind + 1, N, ans, temp);

        temp.push_back(nums[ind]);
        // when ele added in the sub-vector

        subsethelper(nums, ind + 1, N, ans, temp);
    }
};