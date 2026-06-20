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
int sum(Node*root){
    if(root==nullptr){
        return 0;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return leftsum + rightsum + root->data;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << sum(root);
    return 0;
}