#include <bits/stdc++.h>
using namespace std;
#include <vector>
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        queue<Node*> q; //queue contains each level data
        q.push(root);
        
        vector<int> result;
        
        while(!q.empty()){
            int size = q.size();
            int max_val = INT_MIN;
            
            for(int i=0;i<size;i++){ //traversing only upto each level size
                Node* curr = q.front();
                q.pop();
                max_val = max(max_val,curr -> data); //max value of each level
                
                if(curr -> left) //if left child exist push that child to queue
                q.push(curr -> left);
                
                if(curr -> right)//if right child exist push that child to queue
                q.push(curr -> right);
            }
            
            result.push_back(max_val);
            
            
            
                
        }
        
        return result;
        
    }
    

};

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    Solution sol;
    vector<int> result = sol.largestValues(root);

    for(int val : result){
        cout << val << " ";
    }
    return 0;
}