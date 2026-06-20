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
Tree* buildtree(vector<int>&pre){
    Tree*root=new Tree(pre[0]);
    queue<Tree*>q;
    q.push(root);
    int i=1;
    while(q.size()>0&&i<pre.size()){
        Tree*curr=q.front();
        q.pop();
        if(i<pre.size()&&pre[i]!=-1){
            curr->left=new Tree(pre[i]);
            q.push(curr->left);
        }
        i++;
        if(i<pre.size()&&pre[i]!=-1){
            curr->right=new Tree(pre[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
Tree *pre = nullptr;
int mini(Tree*root){
    if(!root){
        return INT_MAX;
    }
    int ans = INT_MAX;
    if(root->left){
        int lt = mini(root->left);
    }
    pre = root;
    
}
int main(){
    vector<int>v={1,22,23,-1,-1,4,5,-1,-1,-1,-1};
    Tree*root=buildtree(v);
    return 0;
}