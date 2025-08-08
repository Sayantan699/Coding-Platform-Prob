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

    cout << "Enter the elements of the array: " << endl;
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

    // Decrease each element of the array by 1

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - 1;
    }

    // adding the size of the array after mod with each element the value after mod is the index where the size of array will be added
    for (int i = 0; i < n; i++)
    {
        int ind = arr[i] % n;
        arr[ind] += n;
    }

    // now if we divide each element of the array by its size we got the accorance
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = arr[i] / n;
    }

    cout << "The occurenrence of 1 to n is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
