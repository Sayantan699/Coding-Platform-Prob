// InterviewBit : Distribute in Circle!

// A items are to be delivered in a circle of size B.

//     Find the position where the Ath item will be delivered if we start from a given position C.

//     NOTE : Items are distributed at adjacent positions starting from C.
// Example Input
// Input 1 :

// A = 2 B = 5 C = 1

// Explanation 1 :

// The first item will be given to 1st position.Second(or last) item will be delivered to 2nd position

#include <iostream>
using namespace std;

int Distribute(int A, int B, int C)
{
    int pos = (C + A - 1) % B; // The first item is already distributed in C pos i.e we only need to move further A-1 steps
    if (pos == 0)              // pos is only 0 when we land in postion B i.e pos 0 is not valid we initialize it to B
        pos = B;
    return pos;
}
int main()
{
    int A, B, C;

    return 0;
}