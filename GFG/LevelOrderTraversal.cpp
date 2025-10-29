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
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> result; //2d vector to store the answers
        while(!q.empty()){
            int size = q.size();
            vector<int> level;  // holds per level’s data
            
            for(int i=0;i<size;i++){
                Node* curr = q.front();//getting the front element of queue and checking its left and  right node
                q.pop(); 
                
                level.push_back(curr -> data);
                
                if(curr -> left)
                    q.push(curr -> left);
                    
                if(curr -> right)
                    q.push(curr -> right);
                
            }
            result.push_back(level);
        }
        
        
        
        return result;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal: " << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}