// Find First and Last Position of Element in Sorted Array

// Given an array of integers nums sorted in non - decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array,
// return [ -1, -1 ].

// You must write an algorithm with O(log n) runtime complexity.

//     Example 1 :

//     Input : nums = [ 5, 7, 7, 8, 8, 10 ],
//             target = 8 Output : [ 3, 4 ]
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

    // Sorting the array before applying Binary search using bubble sort
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    cout << "The elements of the array after bubble sorting are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int k;
    cout << "Enter the element u want to search: ";
    cin >> k;

    int first = -1, last = -1;
    int start = 0, end = n - 1;

    // for first occurence
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    start = 0, end = n - 1;
    // for last occurence
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << "first occurence of " << k << " is: " << first;
    cout << endl;
    cout << "Last occurence of " << k << " is: " << last;
    return 0;
}