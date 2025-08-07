// Missing And Repeating
// Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range
// is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

//                                                                                                                                                                                         Examples :

//     Input : arr[] = [ 2, 2 ] Output : [ 2, 1 ] Explanation : Repeating number is 2 and the missing number is 1.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The elements of the array are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int original_sum = (n * (n + 1)) / 2;

    int modifiedsum = 0;
    for (int i = 0; i < n; i++)
    {
        modifiedsum += arr[i];
    }

    if (modifiedsum == original_sum)
        cout << "No Missing element in the array";
    else
        cout << "The missing element of the array is: " << (original_sum - modifiedsum);

    return 0;
}