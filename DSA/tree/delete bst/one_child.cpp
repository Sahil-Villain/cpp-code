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
Tree* del(Tree*root,int key){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data>key){
        root->left=del(root->left,key);
    }else if(key>root->data){
        root->right=del(root->right,key);
    }else{
        if(root->left==nullptr){
            Tree*temp=root->right;
            delete root;
            return temp;
        }else{
            Tree*temp=root->left;
            delete root;
            return temp;
        }
    }
    
}
void pre(Tree*root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

int main(){
    vector<int>v={10,2,1,3,14,23,12};
    Tree*root=bst(v);
    pre(root);
    cout<<endl;
    del(root,12);
    del(root,23);
    pre(root);
    return 0;
}