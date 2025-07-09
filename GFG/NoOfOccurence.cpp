// Number of occurrence

// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].

// Examples :

//     Input : arr[] = [ 1, 1, 2, 2, 2, 2, 3 ],

//     target = 2 Output : 4 Explanation : target = 2 occurs 4 times in the given array so the output is 4.

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
    cout << "Enter the target element: ";
    cin >> k;

    int start = 0, end = n - 1;
    int mid_index = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            mid_index = mid;
            break;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else
        {
            end = mid - 1;
        }
    }

    if (mid_index == -1)
        return -1;
    int c = 1;
    int left = mid_index - 1;
    while (left >= 0 && arr[left] == k)
    {
        c = c + 1;
        left--;
    }

    int right = mid_index + 1;
    while (right < n && arr[right] == k)
    {
        c = c + 1;
        right++;
    }

    cout << "The number of occurence of the number " << k << " is: " << c;

    return 0;
}