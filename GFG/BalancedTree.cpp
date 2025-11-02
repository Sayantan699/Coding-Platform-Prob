#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  int height(Node* root){ //calculating the height
      if(root == NULL)
        return 0;
      return 1+max(height(root -> left),height(root -> right));
  }
    bool isBalanced(Node* root) {
        // code here
        if(root == NULL)
            return true;
            
        int leftHeight = height(root -> left); 
        int rightHeight = height(root -> right);
        
        int balance = leftHeight - rightHeight;
        
        if( balance <= 1 && balance >= -1 && isBalanced(root -> left) 
        && isBalanced(root -> right)) //checking balance conding and recursively checking blanace for left and right node
            return true;

        return false;
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Solution sol;
    if(sol.isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;
}

