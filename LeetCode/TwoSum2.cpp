// // Two Sum 2;
// Given a 1 - indexed array of integers numbers that is already sorted in non - decreasing order,
// find two numbers such that they add up to a specific target number.
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

//                                                                                                                                                                                                                                                               Return the indices of the two numbers,
//     index1 and index2, added by one as an integer array[index1, index2] of length 2.

//     The tests are generated such that there is exactly one solution.You may not use the same element twice.
//     Your solution must use only constant extra space.

//     Example 1 :

//     Input : numbers = [ 2, 7, 11, 15 ],
//             target = 9 Output : [ 1, 2 ]
//             Explanation : The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [ 1, 2 ].

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    vector<int> ans;

    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] + arr[end] == target)
        {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            break;
        }
        else if (arr[start] + arr[end] < target)
            start++;
        else
            end--;
    }
    cout << "Elements of the array are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    };
    return 0;
}