#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(!r1 && !r2){ //Both NULL
            return true;
        }
        
        if((!r1 && r2) || (!r2 && r1)){ //One exist but another do not exist
            return false;
        }
        
        if(r1 -> data != r2 -> data){ //
            return false;
        }
        
        
        return isIdentical(r1 -> left, r2 -> left) &&  isIdentical(r1 -> right, r2 -> right);
    }
};

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    Solution sol;
    bool identical = sol.isIdentical(root1, root2);
    if (identical) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}