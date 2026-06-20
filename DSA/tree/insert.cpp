#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node*insert(Node*root,int key){
    if(root==nullptr){
        return new Node(key);
    }
    if(key<root->data){
        root->left = insert(root->left, key);
    }
    else if(key>root->data){
        root->right = insert(root->right, key);
    }
    return root;
}
int main(){
    return 0;
}