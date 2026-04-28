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
void printpath(Tree*root,vector<int>&curr){
    if(root==nullptr){
        return;
    }
    curr.push_back(root->data);
    if(root->left==nullptr&&root->right==nullptr){
        for(int i:curr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    printpath(root->left,curr);
    printpath(root->right,curr);
    curr.pop_back();
}
int main(){
    vector<int>v={1,2,3,-1,-1,4,-1,-1,5,-1,-1};
    Tree*root=buildtree(v);
    vector<int>curr;
    printpath(root,curr);
    return 0;
}
