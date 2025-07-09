// Search Insert Position Prob 35
// Given a sorted array of distinct integers and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with

// O(log n) runtime complexity.

// Example 1 :

//     Input : nums = [ 1, 3, 5, 6 ],
//     target = 5 Output : 2

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

    int start = 0, end = n - 1;
    int index = n; // since we are searching for just a big element than our target we will cosnider the length of array

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            index = mid;
            cout << k << "found at index: " << index;
            break;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else
        {
            index = mid;
            end = mid - 1;
        }
    }

    cout << k << " was not found but it shoulde be present at index: " << index;

    return 0;
}