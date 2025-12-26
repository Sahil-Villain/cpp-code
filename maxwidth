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
int maaxwidth(Tree*root){
    if(!root){
        return 0;
    }
    queue<Tree*>q;
    q.push(root);
    int wt=0;
    while(!q.empty()){
        int sizee=q.size();
        wt=max(sizee,wt);
        for(int i=0;i<sizee;i++){
            Tree* curr=q.front();
            q.pop();
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
    }
    return wt;
}
int main(){
    vector<int>v={1,2,3,-1,4,7,5};
    Tree*root=buildtree(v);
    cout<<maaxwidth(root);
    return 0;
}
