//Given a binary tree. Find the inorder traversal of the tree without using recursion
#include <bits/stdc++.h>
#include  <vector>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution{

    public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        stack<int> visited;
        st.push(root);
        visited.push(0);
        while(!st.empty()){

            Node* temp = st.top();
            st.pop();
            bool flag = visited.top();
            visited.pop();
            if(!flag){
            if(temp -> right){
                st.push(temp -> right);
                visited.push(0);
            }

            st.push(temp);
            visited.push(1);

            if(temp -> left){
                st.push(temp ->left);
                visited.push(0);
            }
            }
            else
                ans.push_back(temp -> data);

        }
        return ans;
        

    }
};
int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    Solution obj;
    vector<int> res = obj.inOrder(root);
    for(auto i: res){
        cout<<i<<" ";
    }
    return 0;
}