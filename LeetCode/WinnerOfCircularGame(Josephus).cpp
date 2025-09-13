class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> person(n, 0);
        for (int i = 0; i < person.size(); i++)
        {
            person[i] = i + 1;
        }
        solve(person, k - 1, 0);
        return person[0];
    }

    void solve(vector<int> &person, int k, int ind)
    {
        if (person.size() == 1)
        {
            return;
        }
        ind = (ind + k) % person.size();
        person.erase(person.begin() + ind);
        solve(person, k, ind);
    }
};