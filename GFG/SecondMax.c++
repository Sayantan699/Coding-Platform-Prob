// Second Largest

// Given an array of positive integers arr[], return the second largest element from the array.If the second largest element doesn't
// exist then return -1.

// Note : The second largest element should not be equal to the largest element.

//  Examples :

// Input : arr[] = [ 12, 35, 1, 10, 34, 1 ] Output : 34 Explanation : The largest element of the array is 35 and the second largest element
// is 34.

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

    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int second_max = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != max && arr[i] > second_max)
        {
            second_max = arr[i];
        }
    }

    cout << endl;

    cout << "The 2nd largest element is: " << second_max;

    return 0;
}