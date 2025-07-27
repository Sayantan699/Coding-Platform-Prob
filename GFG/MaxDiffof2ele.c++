// // minelemum Difference between Two Elements such that Larger Element Appears after the Smaller Element

// Given an array of integers, the task is to find the minelemum difference between any two elements such that larger element appears
// after the smaller number.We mainly need to find minelemum difference in an inversion(larger before smaller)

//     Note : If no such pair exists,return -1.

//     Examples :

//     Input : arr = [ 2, 3, 10, 6, 4, 8, 1 ] Output : 8 Explanation : The minelemum difference is between 10 and 2.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    cout << "The elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // BRUTE FORCE APPOROACH TC - O(n^2)
    // int minele = -1;
    // int diff;
    // for (int i = 0; i < n - 1; i++)
    // {

    //     for (int j = i + 1; j < n; j++)
    //     {

    //         if (arr[j] > arr[i])
    //         {
    //             diff = arr[j] - arr[i];
    //             minele = max(minele, diff);
    //         }
    //     }
    // }
    // if (minele <= -1)
    //     cout << "No such pair exits!!";
    // else
    //     cout << minele;

    // Optimized approach TC - O(n)

    int minele = arr[0];
    int max_diff = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > minele)
        {
            max_diff = max(max_diff, arr[i] - minele);
        }
        else
            minele = arr[i];
    }
    if (max_diff <= 0)
        cout << "No such pair exists!!" << endl;
    else
        cout << "Maximum Difference: " << max_diff << endl;

    return 0;
}