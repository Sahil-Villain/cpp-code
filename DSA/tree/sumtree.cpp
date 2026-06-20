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
int sum(Tree*root){
    if(!root){
        return 0;
    }
    int lt=sum(root->left);
    int rt=sum(root->right);
    return root->data+lt+rt;
}
void printpath(Tree*root){
    if(root==nullptr){
        return;
    }
    
    cout<<sum(root)<<" ";
    printpath(root->left);
    printpath(root->right);
}
int main(){
    vector<int>v={1,2,3,-1,-1,5,4,-1,-1,-1,-1};
    Tree*root=buildtree(v);
    vector<int>curr;
    // sumtree(root);
    printpath(root);
    // sum(root);
    // print(root);
    return 0;
}