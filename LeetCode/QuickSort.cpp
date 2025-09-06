class Solution
{
public:
    vector<int> sortArray(vector<int> &arr)
    {
        srand(time(0)); // seed for randomness
        quicksort(arr, 0, arr.size() - 1);
        return arr;
    }

    int partition(vector<int> &arr, int start, int end)
    {
        // 🔑 one line: choose a random pivot and swap with last
        int randomPivot = start + rand() % (end - start + 1);
        swap(arr[randomPivot], arr[end]);

        int pivot = arr[end];
        int pos = start;
        for (int i = start; i < end; i++)
        {
            if (arr[i] < pivot)
            {
                swap(arr[i], arr[pos]);
                pos++;
            }
        }
        swap(arr[pos], arr[end]); // put pivot in correct place
        return pos;
    }

    void quicksort(vector<int> &arr, int start, int end)
    {
        if (start >= end)
            return; // base case
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
};
