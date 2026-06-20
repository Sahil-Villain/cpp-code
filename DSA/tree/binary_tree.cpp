#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree *left;
    Tree*right;
    Tree(int val){
        data = val;
        left = right = nullptr;
    }
};
// void bt(vector<int){
//     // Tree *root = new Tree(val[0]);
//     // return root;
//     if(i==val.size()/2){
//         return;
//     }
//     bt(root->left, val, i + 1);
//     root->left = new Tree(val[2 * i + 1]);
//     bt(root->right, val, i + 1);
//     root->right = new Tree(val[2 * i + 2]);
//     return;
// }

void ino(Tree*root){
    if(!root){
        return;
    }
    ino(root->left);
    cout << root->data << " ";
    ino(root->right);
}
int main(){
    // vector<int> val = {1, 2, 3, -1, 4, -1, -1, -1, -1};
    vector<int> val = {1, 2, 3, 4, 5};
    // Tree *root = bt(val, 0);
    // Tree* root = new Tree(val[0]);
    // bt(root, val, 1);
    ino(root);
    return 0;
}