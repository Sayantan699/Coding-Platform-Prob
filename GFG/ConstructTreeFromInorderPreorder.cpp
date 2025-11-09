#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    int Find(vector<int> &in,int start,int end,int target){
        for(int i=start;i<=end;i++){
            if(in[i] == target)
                return i;
        }
        return -1;
    }
    Node *Tree(int ind,int Instart,int InEnd,vector<int> &in, vector<int> &pre){
        if(Instart > InEnd)
            return NULL;
        Node* node = new Node(pre[ind]);
        int pos = Find(in,Instart,InEnd,pre[ind]);
        node -> left = Tree(ind+1,Instart,pos-1,in,pre);
        node -> right = Tree(ind+(pos-Instart+1),pos+1,InEnd,in,pre);
        return node;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        Node* node = Tree(0,0,inorder.size()-1,inorder,preorder);
        return node;
    }
};