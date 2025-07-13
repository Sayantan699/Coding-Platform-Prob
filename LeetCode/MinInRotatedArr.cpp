// 153.Find Minimum in Rotated Sorted Array

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
// For example, the array nums = [ 0, 1, 2, 4, 5, 6, 7 ] might become :

//     [ 4, 5, 6, 7, 0, 1, 2 ] if it was rotated 4 times.[0, 1, 2, 4, 5, 6, 7]
//     if it was rotated 7 times.Notice that rotating an array[a[0], a[1], a[2], ..., a[n - 1]]
//     1 time results in the array[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]]
//         .

//     Given the sorted rotated array nums of unique elements,

//     return the minimum element of this array.

//     You must write an algorithm that runs in

//     O(log n) time.

//     Example 1 :

//     Input : nums = [ 3, 4, 5, 1, 2 ] Output : 1 Explanation : The original array was[1, 2, 3, 4, 5] rotated 3 times.

#include <iostream>
using namespace std;

int main()
{

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The original array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int start = 0, end = n - 1, ans = arr[0];

    // checking if the array is rotated or not
    if (arr[start] <= arr[end])
        ans = arr[start];
    else
    {

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= arr[0]) // i.e sorted in left side i.e go to right side
                start = mid + 1;
            else
            {
                ans = arr[mid];
                end = mid - 1;
            }
        }
    }

    cout << "The min element of the rotated arrya is: " << ans;

    return 0;
}