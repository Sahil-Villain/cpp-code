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
Tree*create(int arr[],int st,int end){
    if(st>end){
        return nullptr;
    }
    int mid=st+(end-st)/2;
    Tree*root=new Tree(arr[mid]);
    root->left=create(arr,st,mid-1);
    root->right=create(arr,mid+1,end);
    return root;
}
void inorder(Tree*root){
    if(!root){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    // vector<int>v={1,2,3,-1,-1,4,5,-1,-1,-1,-1};
    int arr[8]={1,2,3,4,5,7,8,9};
    Tree*root=create(arr,0,7);
    inorder(root);
    return 0;
}