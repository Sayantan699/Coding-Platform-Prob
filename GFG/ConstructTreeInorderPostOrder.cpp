#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
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
    Node *Tree(int ind,int Instart,int InEnd,vector<int> &in, vector<int> &post){
        if(Instart > InEnd)
            return NULL;
        Node* node = new Node(post[ind]);
        int pos = Find(in,Instart,InEnd,post[ind]);
    //In Post Order - Sequence is Left -> Right -> Node since we are using recursiong the process is reverse
        node -> right = Tree(ind-1,pos+1,InEnd,in,post);
        node -> left = Tree(ind-(InEnd-pos)-1,Instart,pos-1,in,post);
        
        return node;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        Node* node = Tree(postorder.size()-1,0,inorder.size()-1,inorder,postorder);
        return node;
        
    }
};
int main(){
    vector<int> inorder = {4, 2, 1, 5, 3, 6};
    vector<int> postorder = {4, 2, 5, 6, 3, 1};

    Solution sol;
    Node* root = sol.buildTree(inorder, postorder);

    // Function to print inorder traversal of the constructed tree
    function<void(Node*)> printInorder = [&](Node* node) {
        if (node == NULL) return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    };

    printInorder(root);
    return 0;
}