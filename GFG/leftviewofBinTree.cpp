#include <bits/stdc++.h>
using namespace std;

//Declaring the structure of Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//Function to return a list containing elements of left view of binary tree.
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            ans.push_back(q.front() -> data); //storing only the left part data of level
            
            while(n--){ //emptying the queue and storing child node if any
                Node* temp = q.front();
                q.pop();
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
                 
            }
        }
        
        return ans;
        
    }

};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    Solution sol;
    vector<int> result = sol.leftView(root);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}