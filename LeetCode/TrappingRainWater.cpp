// // Trapping rain water

// Given n non - negative
// integers representing an elevation map where the width of each bar is 1,compute how much water it can trap after raining.

// Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ] Output : 6 Explanation : The above elevation map(black section)
// is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].

// In this case,6 units of rain water(blue section) are being trapped.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter the height of the building: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << "Height of the buildings are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << height[i] << " ";
    }

    cout << endl;

    vector<int> leftmax(n);
    vector<int> rightmax(n);

    leftmax[0] = 0;

    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], height[i - 1]);
    }

    rightmax[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], height[i + 1]);
    }

    int minheight = 0;

    int waterstore = 0;
    for (int i = 0; i < n; i++)
    {
        minheight = min(leftmax[i], rightmax[i]);
        if (minheight - height[i] >= 0)
        {
            waterstore += minheight - height[i];
        }
    }

    cout << waterstore;
    return 0;
}