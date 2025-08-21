// // Total moves for bishop
// Given the position of a Bishop(A, B)
// on an 8 * 8 chessboard.

// Your task is to count the total number of squares that can be visited by the Bishop in one move.
// The position of the Bishop is denoted using row and column number of the chessboard.

// Problem Constraints 1 <= A,B <= 8

//         Input Format
//         First argument is an integer A denoting the row number of the bishop.

//         Second argument is an integer B denoting the column number of the bishop.

//          Output Format
//          Return an integer denoting the total number of squares that can be visited by the Bishop in one move.

//          Example :-
//         Input 1 : A = 4 B = 4
//         Output 1 : 13

#include <iostream>
#include <algorithm>
using namespace std;
int BishopMoves(int A, int B)
{
    int total_moves = 0;
    int c1 = min(8 - A, 8 - B); // For South-west i.e no of rows and cols both increasing i.e 8 - A and 8-B
    int c2 = min(8 - A, B - 1); // For South-East i.e no of rows inc but cols dec  i.e 8 - A and B-1
    int c3 = min(A - 1, 8 - B); // For North-west i.e no of rows dec but cols increasing i.e A-1, 8 - B
    int c4 = min(A - 1, B - 1); // For North-east i.e no of rows and cols both decreasing i.e A-1, B-1
    total_moves = c1 + c2 + c3 + c4;
    return total_moves;
}
int main()
{
    int row, col;
    cout << "Enter the row number of Bishop: ";
    cin >> row;

    cout << "Enter the col number of Bishop: ";
    cin >> col;

    cout << "Total number of min moves perform by Bishop: " << BishopMoves(row, col);
    return 0;
}
