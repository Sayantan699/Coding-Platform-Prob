#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int Find(int in[],int start,int end,int target){
        for(int i=start;i<=end;i++){
            if(in[i] == target)
                return i;
        }
        return -1;
    }
    
    bool solve(int preorder[], int inorder[], int postorder[],
               int inStart, int inEnd,
               int &preIndex, int &postIndex, int N) {

        // Base condition
        if (inStart > inEnd)
            return true;

        // If any index goes out of bound
        if (preIndex >= N || postIndex < 0)
            return false;

        // Root element according to preorder
        int rootVal = preorder[preIndex++];
        int pos = Find(inorder, inStart, inEnd, rootVal);
        if (pos == -1) return false;

        // 🧮 Your approach — using index formulas for left/right subtrees
        // Left subtree indices:
        // leftStart = inStart
        // leftEnd = pos - 1
        // Right subtree indices:
        // rightStart = pos + 1
        // rightEnd = inEnd

        // Recur left subtree
        bool left = solve(preorder, inorder, postorder, inStart, pos - 1, preIndex, postIndex, N);

        // Recur right subtree
        bool right = solve(preorder, inorder, postorder, pos + 1, inEnd, preIndex, postIndex, N);

        // Now check if the current root matches postorder
        if (postorder[postIndex] != rootVal)
            return false;
        postIndex--;

        return left && right;
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        // Your code goes here
        int preIndex = 0;
        int postIndex = N-1;
             
       return solve(preorder, inorder, postorder, 0, N - 1, preIndex, postIndex, N);
        
    }
};

int main(){
    int inorder[] = {4, 2, 1, 5, 3, 6};
    int preorder[] = {1, 2, 4, 3, 5, 6};
    int postorder[] = {4, 2, 5, 6, 3, 1};
    int N = sizeof(inorder) / sizeof(inorder[0]);

    Solution sol;
    bool result = sol.checktree(preorder, inorder, postorder, N);

    if (result)
        cout << "The traversals represent the same tree." << endl;
    else
        cout << "The traversals do not represent the same tree." << endl;

    return 0;
}