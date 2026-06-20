#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
int count(Node*root){
    if(root==nullptr){
        return 0;
    }
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return leftcount + rightcount + 1;
}
int findmin(Node*root){
    if(root==nullptr){
        return INT_MAX;
    }
    int leftdata = findmin(root->left);
    int rightdata = findmin(root->right);
    return min(root->data, min(leftdata, rightdata));
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "Min: " << findmin(root);
    return 0;
}