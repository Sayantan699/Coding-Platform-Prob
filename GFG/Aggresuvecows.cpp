// Aggressive Cows

// You are given an array with unique elements of stalls[], which denote the position of a stall.
// You are also given an integer k which denotes the number of aggressive cows.
// Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

//     Input : stalls[] = [ 1, 2, 4, 8, 9 ],

//     k = 3 Output : 3
//     Explanation : The first cow can be placed at stalls[0],the second cow can be placed at stalls[2] and
//     the third cow can be placed at stalls[3].The minimum distance between cows,in this case, is 3, which also is the largest
//     among all possible ways.
#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);

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

    int start = arr[0], end, mid, ans;

    sort(arr.begin(), arr.end()); // Sorted the array in increasing order

    end = arr[n - 1] - arr[0];
    while (start <= end)
    {
        int count = 0, pos = arr[0];
        mid = start + (end - start) / 2;
        for (int i = 1; i < n; i++)
        {
            if (pos + mid <= arr[i])
            {
                count++;
                pos = arr[i];
            }
            if (count < k)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
        }
    }

    return ans;
}