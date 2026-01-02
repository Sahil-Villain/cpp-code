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
void inorder(Tree*root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);

}
Tree*search(Tree*root,int key){
    if(!root || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}
Tree*pre(Tree*root,Tree*p){
    Tree *pred = nullptr;
    while(root){
        if(p->data>root->data){
            pred = root;
            root = root->right;
        }else{
            root = root->left;
        }

    }
    return pred;
}
int main(){
    vector<int>v={10,2,1,3,14,23,12};
    Tree*root=bst(v);
    inorder(root);
    Tree *p = search(root, 3);
    Tree *pred = pre(root, p);
    cout << pred->data;
    return 0;
}
