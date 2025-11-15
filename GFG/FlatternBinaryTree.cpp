#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    void flatten(Node *root) {
        
        Node* curr = root;
        while(curr != NULL){
            if(!curr -> left){
                curr = curr -> right;
            }
            else{
                Node* temp = curr -> left;
                while (temp->right != NULL && temp->right != curr){ //if temp right points to NULL or no link is there
                    temp = temp -> right;
                }
                //Now points to right most node
                if(temp -> right == NULL){ //i.e no link is created
                    temp -> right = curr -> right; //link created
                    curr -> right = curr -> left;
                    curr -> left = NULL;
                    curr = curr -> right;
                }

            }
        }
        return;
    }
};
int main(){
    Node* root = new Node();
    root -> data = 1;
    root -> left = new Node();
    root -> left -> data = 2;
    root -> right = new Node();
    root -> right -> data = 3;
    root -> left -> left = new Node();
    root -> left -> left -> data = 4;
    root -> left -> right = new Node();
    root -> left -> right -> data = 5;
    Solution obj;
    obj.flatten(root);
    Node* curr = root;
    while(curr != NULL){
        cout<<curr -> data<<" ";
        curr = curr -> right;
    }
    return 0;
}