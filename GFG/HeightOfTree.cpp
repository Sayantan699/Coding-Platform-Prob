#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == NULL)
            return 0;
            
        if(root -> left == NULL && root -> right == NULL){
                return 0;
        }
        
        return 1 + max(height(root -> left),height(root -> right));
            
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int h = sol.height(root);
    cout << "Height of the tree: " << h << endl;

    return 0;
}