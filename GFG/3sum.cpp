// Triplet Sum in Array

// Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

// Return true if such a triplet exists,otherwise, return false.

// Examples

//     Input : arr[] = [ 1, 4, 45, 6, 10, 8 ],
//     target = 13 Output : true
//     Explanation : The triplet{1, 4, 8} sums up to 13

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

    sort(arr.begin(), arr.end());

    vector<int> ans;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int first = arr[i];
        int sumtwo = target - first;

        int start = i + 1, end = n - 1;
        // now applying two sum to find the other two numbers
        while (start < end)
        {
            int currentsum = arr[start] + arr[end];
            if (currentsum == sumtwo)
            {
                cout << "Triplet found and the elements are: " << first << " " << arr[start] << " " << arr[end];
                res = 1;
                break;
            }
            else if (currentsum < sumtwo)
                start++;
            else
                end--;
        }
        if (res == 1)
            break;
    }
    if (res == 0)
    {
        cout << "Triplet not found!!";
    }
    return 0;
}