// Missing And Repeating
// Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range
// is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

//                                                                                                                                                                                         Examples :

//     Input : arr[] = [ 2, 2 ] Output : [ 2, 1 ] Explanation : Repeating number is 2 and the missing number is 1.
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    // The missing element = original sum - (modified sum - duplicate)
    int modifiedsum = 0;
    int duplicate = -1;
    unordered_map<int, int> freq; // act as a key value pair to store the element and the number of times its appeared
    for (int i = 0; i < n; i++)
    {
        modifiedsum += arr[i];
        freq[arr[i]]++;
        if (freq[arr[i]] == 2)
        {
            duplicate = arr[i];
        }
    }

    int missing = original_sum - (modifiedsum - duplicate);
    cout << "The repeating number is: " << duplicate << endl;
    cout << "The missing number is: " << missing << endl;

    return 0;
}