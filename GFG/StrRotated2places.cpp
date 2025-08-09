// String Rotated by 2 Places

// Given two strings s1 and s2.Return true if the string s2 can be obtained by rotating(in any direction)
// string s1 by exactly 2 places, otherwise, false.

// Note : Both rotations should be performed in same direction chosen initially.

//        ExamplesInput : s1 = "amazon",
//                        s2 = "azonam" Output : true
//                        Explanation : "amazon" can be rotated anti - clockwise by two places, which will make it as "azonam".
#include <iostream>
using namespace std;
int main()
{
    void rotateclockwise(string & s)
    {
        char c = s[s.size() - 1];
        int ind = s.size() - 2;
        while (ind >= 0)
        {
            s[ind + 1] = s[ind];
            ind--;
        }
        s[0] = c;
    }

    void rotateanticlockwise(string & s)
    {
        char c = s[0];
        int ind = 1;
        while (ind < s.size())
        {
            s[ind - 1] = s[ind];
            ind++;
        }
        s[s.size() - 1] = c;
    }
    bool isRotated(string & s1, string & s2)
    {
        // code here
        if (s1.size() != s2.size())
            return false;

        string clockwise = s1;

        rotateclockwise(clockwise);
        rotateclockwise(clockwise);
        if (clockwise == s2)
            return true;

        string anticlockwise = s1;

        rotateanticlockwise(anticlockwise);
        rotateanticlockwise(anticlockwise);

        if (anticlockwise == s2)
            return true;

        return false;
    }
}