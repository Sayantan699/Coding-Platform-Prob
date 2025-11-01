#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root == NULL)
            return ;
        
        Node* temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;
        
        //Move to left subtree
        mirror(root -> left);
        
        //Move to right subtree
        
        mirror(root -> right);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    sol.mirror(root);
    // The tree is now mirrored. You can add code to print or verify the structure if needed.

    cout << "The tree has been mirrored." << endl;

    return 0;
}