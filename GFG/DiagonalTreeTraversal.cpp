#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    void Find(Node *root,int pos,int &l){
        if(root == NULL)
            return;
        l = max(l,pos);
        Find(root -> left,pos+1,l);
        Find(root -> right,pos,l);
    }
    void FindDiagonal(Node *root,int pos,vector<vector<int>> &ans){ //storing the data of diagoanl element in ans
        if(root == NULL)
            return;
        ans[pos].push_back(root -> data);
        FindDiagonal(root -> left,pos+1,ans);
        FindDiagonal(root -> right,pos,ans);
    }
    
    vector<int> diagonal(Node *root) {
        // code here
        int l=0;//Left most diagonal
        Find(root,0,l);
        vector<vector<int>> ans(l+1);
        FindDiagonal(root,0,ans);
        vector<int> result;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                result.push_back(ans[i][j]);
            }
        }
        return result;
    }
};
