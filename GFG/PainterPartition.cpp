// The Painter's Partition Problem-II

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i]
// where arr[] is an array of n integers.
// He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

// Return the minimum time to get this job done if all painters start together with the constraint that any painter will only
// paint continuous boards,say boards numbered[2, 3, 4] or only board[1] or nothing but not boards[2, 4, 5].

//     Examples :

// Input : arr[] = [ 5, 10, 30, 20, 15 ],
// k = 3 Output : 35 Explanation : The most optimal way will be :
// Painter 1 allocation : [ 5, 10 ], Painter 2 allocation : [30], Painter 3 allocation : [ 20, 15 ],
// Job will be done when all painters finish i.e.at time = max(5 + 10, 30, 20 + 15) = 35

#include <iostream>
#include <vector>
using namespace std;

int minTime(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int start = arr[0];
    int end = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > start)
            start = arr[i]; // max element in arr -> min possible time
        end += arr[i];      // sum of all elements -> max possible time
    }

    int ans = end; // initialize with maximum possible time
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int time_allocate = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            time_allocate += arr[i];

            if (time_allocate > mid)
            {
                count++;
                time_allocate = arr[i];
            }
        }
        if (count <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    // return minimum time
    return ans;
}
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

    int k;
    cout << "Enter the no of painters: ";
    cin >> k;

    cout << minTime(arr, k);

    return 0;
}