class Solution
{
public:
    int towerOfHanoi(int n, int from, int to, int aux)
    {
        // code here
        if (n == 1)
        { // If no of disk is 1 there will be only 1 case moving disk from source to destination
            return 1;
        }

        // +1 for the movement of the largest disk from source to destination
        return towerOfHanoi(n - 1, from, to, aux) + 1 + towerOfHanoi(n - 1, aux, from, to);
    }
};