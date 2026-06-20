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
Tree*create(Tree*root,int key){
    if(!root){
        return new Tree(key);
    }
    if(key<root->data){
        root->left=create(root->left,key);
    }else{
        root->right=create(root->right,key);
    }
    return root;
}
Tree*bst(vector<int>&val){
    Tree*root=nullptr;
    for(int i:val){
        root=create(root,i);
    }
    return root;
}
bool isvalid(Tree*root,int min=INT_MIN,int max=INT_MAX){
    if(root==nullptr){
        return true;
    }
    if(root->data>=max|| root->data<=min){
        return false;
    }
    return isvalid(root->left,min,root->data)&&isvalid(root->right,root->data,max);
}
int main(){
    vector<int>v={1,2,3,4,5,7,8,9};
    Tree*root=bst(v);
    if(isvalid(root)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}