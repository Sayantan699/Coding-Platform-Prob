// Find the Safe Position

// There are n people standing in a circle(numbered clockwise 1 to n) waiting to be executed.The counting begins at point 1 in the
// circle and proceeds around the circle in a fixed direction(clockwise).

// In each step,a certain number of people are skipped and the next person is executed.The elimination proceeds around the
// circle(which is becoming smaller and smaller as the executed people are removed), until only the last person remains,
// who is given freedom.Given the total number of persons n and a number k which indicates that k - 1 persons are skipped and kth
// person is killed in circle.The task is to choose the place in the initial circle so that you are the last one remaining and
// so survive.

//                                                                                                                                                                                                                                                                                                                                       Example 1 :

//     Input : n = 2,
//       k = 1 Output : 2 Explanation : Here, n = 2 and k = 1, then safe position is 2 as the person at 1st position will be Killed

class Solution
{
public:
    int safePos(int n, int k)
    {
        // code here
        vector<int> person(n, 0);
        for (int i = 0; i < person.size(); i++)
        {
            person[i] = i + 1; // Initializing persons from 1 to n
        }
        solve(person, k - 1, 0);
        return person[0]; // The last remaining person
    }

    void solve(vector<int> &person, int k, int ind)
    {
        if (person.size() == 1)
        {
            return;
        }
        // Since in Josephus Problem the person are standing in a circular manner but we are using a 1D vector we need to come back to the first positon
        // when we encounter the last person
        ind = (ind + k) % person.size();

        person.erase(person.begin() + ind); // Removing the person from the specified index and reducing the size of person vector
        solve(person, k, ind);
    }
};
