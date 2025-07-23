// Segregate 0s and 1s

// Given an array arr consisting of only 0's and 1's in random order.
// Modify the array in - place to segregate 0s onto the left side and
// 1s onto the right side of the array.

// Examples :

//     Input : arr[] = [ 0, 0, 1, 1, 0 ] Output : [ 0, 0, 0, 1, 1 ]
//     Explanation : After segregation,all the 0's are on the left and 1's are on the right.Modified array will be[0, 0, 0, 1, 1].

#include <vector>
#include <iostream>
#include <algorithm>
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

    // sort(arr.begin(), arr.end());

    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] == 0)
            start++;
        else if (arr[end] == 0)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else
            end--;
    }

    cout << "Elements of the array after sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}