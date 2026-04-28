#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int data;
    Tree*left;
    Tree*right;
    Tree(int val){
        data=val;
        left=right=nullptr;
    }
};
Tree*insert(Tree*root,int key){
    if(!root){
        return new Tree(key);
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }else{
        root->right=insert(root->right,key);
    }
    return root;
}
Tree*bst(vector<int>&v){
    Tree*root=nullptr;
    for(int i:v){
        root=insert(root,i);
    }
    return root;
}
Tree*func(vector<int>&v,int &i,int min,int max){
    if(i>=v.size()){
        return nullptr;
    }
    Tree *root = nullptr;
    if(v[i]>min&&v[i]<max){
        root = new Tree(v[i++]);
        root->left = func(v, i, min, root->data);
        root->right = func(v, i, root->data, max);
    }
    return root;
}
void ino(Tree*root){
    if(!root){
        return;
    }
    ino(root->left);
    cout << root->data << " ";
    ino(root->right);
}
int main(){
    vector<int>v={7,3,1,4,8,9};
    int i = 0;
    Tree *root = func(v, i, INT_MIN, INT_MAX);
    ino(root);
    return 0;
}
