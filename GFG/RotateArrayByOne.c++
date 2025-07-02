// Rotate Array by One

//     Given an array arr,
//     rotate the array by one position in clockwise direction.

//     Examples :

//     Input : arr[] = [ 1, 2, 3, 4, 5 ] Output : [ 5, 1, 2, 3, 4 ]
//     Explanation : If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "The original array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int last = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[0] = last;

    cout << "The Rotated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

       return 0;
}