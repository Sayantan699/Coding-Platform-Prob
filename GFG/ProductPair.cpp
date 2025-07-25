// Product Pair

// Given an array,arr[] of distinct elements, and a number x,
// find if there is a pair in arr[] with a product equal to x.
// Return true if there exists such pair otherwise false.

// Examples :

//     Input : arr[] = [ 10, 20, 9, 40 ], x = 400 Output : true Explanation : As 10 * 40 = 400, the answer is true.
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

    bool found = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] * arr[j] == target)
            {
                cout << "true" << endl;
                found = true;
                break;
            }
        }
    }

    if (found == false)
    {
        cout << "false" << endl;
    }
    return 0;
}