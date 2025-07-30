// Four Elements

// Given an array A of N integers.
// You have to find whether a combination of four elements in the array whose sum is equal to a given value X exists or not.

// Example 1 :  Input : N = 6 A[] = {1, 5, 1, 0, 6, 0} X = 7 Output : 1

// Explantion : 1,5, 1, 0 are the four elements which makes sum 7.

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

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int first = arr[i];
            int second = arr[j];
            int sumtwo = target - (first + second);

            int start = i + 2, end = n - 1;
            // now applying two sum to find the other two numbers
            while (start < end)
            {
                int currentsum = arr[start] + arr[end];
                if (currentsum == sumtwo)
                {
                    cout << "quadraplet found and the elements are: " << first << " " << arr[start] << " " << arr[end];
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
    }
    if (res == 0)
    {
        cout << "Triplet not found!!";
    }
    return 0;
}