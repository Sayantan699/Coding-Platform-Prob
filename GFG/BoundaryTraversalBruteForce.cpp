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
    vector<int> leftBoundary(Node* root){
        vector<int> leftnodes;
        if (!root) return leftnodes;
        //checking if the root itself is a leaf or not...
        if(!(root ->left == NULL && root -> right == NULL))
            leftnodes.push_back(root -> data);
            
        Node *temp = root -> left;
        while(temp){
            //checking if its a leaf node
            if(temp ->left == NULL && temp -> right == NULL){
                break;
            }
            leftnodes.push_back(temp->data);
            if(temp -> left)
                temp = temp -> left;
            else
                temp = temp -> right;
        }
        return leftnodes;
    }
    void leaf(Node* root,vector<int> &leafnodes){
        
        if(root == NULL)
            return;
        if (!root->left && !root->right) {
            leafnodes.push_back(root->data);
            return;
        }
        leaf(root -> left,leafnodes);
        leaf(root -> right,leafnodes);
        
    }
    vector<int> RightBoundary(Node* root){
        vector<int> rightnodes;
        if (!root) return rightnodes;
        Node *temp = root -> right;
        while(temp){
            //checking if its a leaf node
            if(temp ->left == NULL && temp -> right == NULL){
                break;
            }
            rightnodes.push_back(temp->data);
            if(temp -> right)
                temp = temp -> right;
            else
                temp = temp -> left;
        }
        return rightnodes;
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        if(!root)
            return result;
        
        vector<int> leftboundaryele = leftBoundary(root);
        vector<int> leafnodes;
        leaf(root, leafnodes);

        // right boundary
        vector<int> rightboundaryele = RightBoundary(root);

        // 1. left boundary
        result.insert(result.end(), leftboundaryele.begin(), leftboundaryele.end());

        // 2. leaf nodes
        result.insert(result.end(), leafnodes.begin(), leafnodes.end());

        // 3. right boundary reversed
        for (int i = rightboundaryele.size() - 1; i >= 0; i--) {
            result.push_back(rightboundaryele[i]);
        }

        return result;
        
    }
};
int main(){
    return 0;
}