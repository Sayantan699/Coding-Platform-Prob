// Search in a sorted Matrix
// Given a strictly sorted 2D matrix mat[][] of size n x m and a number x.
// Find whether the number x is present in the matrix or not.
// Note : In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row(i != 0)
// is greater than the last element of the(i - 1) th row.

//                                                                                                                                                                                                                           Examples :

//     Input : mat[][] = [ [ 1, 5, 9 ], [ 14, 20, 21 ], [ 30, 34, 43 ] ],
//     x = 14 Output : true Explanation : 14 is present in the matrix, so output is true.

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;

    cout << "Enter the number of column(it should be equal to row): ";
    cin >> col;

    vector<vector<int>> arr(row, vector<int>(col));

    // vector << int >> arr(row, vector<int> col);

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The elements of the array are: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int x;
    cout << "Enter the target: ";
    cin >> x;
    int i = 0, j = col - 1;
    while (i < row && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << x << " founded at row: " << i + 1 << " and column col: " << j + 1;
            return 0;
        }
        else if (arr[i][j] < x)
            i++;
        else
            j--;
    }
    cout << x << " not found in the matrix." << endl;
    return 0;
}