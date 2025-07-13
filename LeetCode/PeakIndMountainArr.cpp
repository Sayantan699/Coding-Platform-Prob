// 852.Peak Index in a Moutain Array
// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in
//      O(log(n)) time complexity.

// Example 1 :

// Input : arr = [ 0, 1, 0 ]

// Output : 1
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

    // Sorting the array before applying Binary search using selection sort
    // int index;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     index = i;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[index] > arr[j])
    //             swap(arr[index], arr[j]);
    //     }
    // }

    // cout << "The elements of the array after selection sorting are: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << endl;

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            cout << arr[mid];
            break;
        }
        else if (arr[mid] > arr[mid + 1])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}