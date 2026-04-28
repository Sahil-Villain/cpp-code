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
void print(Tree* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int sumtree(Tree*root){
    if(root==nullptr){
        return 0;
    }
    int lt=sumtree(root->left);
    int rt=sumtree(root->right);
    root->data+=lt+rt;
    return root->data;
}
int main(){
    vector<int>v={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Tree*root=buildtree(v);
    sumtree(root);
    print(root);
    return 0;
}
