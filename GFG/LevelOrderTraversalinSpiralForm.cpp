#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        
       vector<int> ans;
        
        if(root == NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
        
        // starting with right -> left for the root node
        bool reverseOrder = true; //false means left -> right and true means right -> left
        while(!q.empty()){
             vector<int> level;//store each level data as per given condition
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* curr = q.front();
                
                level.push_back(curr -> data);
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
                    
                q.pop();
                
            }
            
            //reversing the data in vector level
            if(reverseOrder)
            reverse(level.begin(),level.end());
            
            for(int val : level)
                ans.push_back(val);
            
            reverseOrder = !reverseOrder;
        }
        
        
       
       return ans;
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Solution sol;
    vector<int> spiralOrder = sol.findSpiral(root);
    for(int val : spiralOrder)
        cout << val << " ";
    cout << endl;
    return 0;
}