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
        Node* curr = root;
        while(curr != NULL){
            if(!curr -> left){
                ans.push_back(curr -> data);
                curr = curr -> right;
            }
            else{
                Node* temp = curr -> left;
                while (temp->right != NULL && temp->right != curr){ //if temp right points to NULL or no link is there
                    temp = temp -> right;
                }
                //Now points to right most node
                if(temp -> right == NULL){ //i.e no link is created
                    temp -> right = curr; //link created
                    curr = curr -> left;
                }
                if(temp -> right == curr){ //link was created i.e we already travesed the subtree
                    temp -> right = NULL;//break the link
                    ans.push_back(curr -> data);
                    curr = curr -> right;
                }

            }
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