#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // since number of row=col I am taking n
    int n;
    cout << "Enter the value of n(row=col): ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The elements of the array are: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reverse
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }

    cout << "The array after rotating 90deg is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}