// // Permutation 2
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1 :

//     Input : nums = [ 1, 1, 2 ] Output : [ [ 1, 1, 2 ],
//                                           [ 1, 2, 1 ],
//                                           [ 2, 1, 1 ] ]

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        vector<vector<int>> ans;

        permutehelper(nums, ans, 0);
        return ans;
    }
    void permutehelper(vector<int> &arr, vector<vector<int>> &ans, int ind)
    {
        if (ind == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        vector<bool> visited(21, 0); // size 21 each initialized to 0
        for (int i = ind; i < arr.size(); i++)
        {
            if (visited[arr[i] + 10] == 0)
            {                           // to check if the num is already visited or not.if not then check the next unique num
                swap(arr[ind], arr[i]); // swapping
                permutehelper(arr, ans, ind + 1);
                swap(arr[ind], arr[i]); // Backtracking for  next loop iteration
                visited[arr[i] + 10] = 1;
            }
        }
    }
};