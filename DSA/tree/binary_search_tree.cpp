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
bool search(Tree*root,int key){
    if(!root){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
void pre(Tree*root){
    if(!root){
        return;
    }
    pre(root->left);
    cout<<root->data<<" ";
    pre(root->right);
}
int main(){
    vector<int>v={10,2,1,3,14,23,12};
    Tree*root=bst(v);
    if(search(root,10)){
        cout<<"yes";
    }
    return 0;
}