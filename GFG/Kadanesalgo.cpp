// Kadane's Algo

// You are given an integer array arr[].
// You need to find the maximum sum of a subarray(containing at least one element) in the array arr[].

// Note : A subarray is a continuous part of an array.

// Examples :

//     Input : arr[] = [ 2, 3, -8, 7, -1, 2, 3 ]
//     Output : 11
//     Explanation : The subarray[7, -1, 2, 3] has the largest sum 11.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Required for INT_MIN
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

    int maxi = INT_MIN;
    int prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        maxi = max(prefix, maxi);
        if (prefix < 0)
            prefix = 0;
    }
    cout << maxi;
    return 0;
}