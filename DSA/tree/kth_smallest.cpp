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
int preo = 0;
int smallest(Tree*root,int k){
    if(!root){
        return -1;
    }
    if(root->left){
        int lt = smallest(root->left, k);
        if(lt!=-1){
            return lt;
        }
    }
    if(preo+1==k){
        return root->data;
    }
    preo++;
    if(root->right){
        int rt = smallest(root->right, k);
        if(rt!=-1){
            return rt;
        }
    }
    return -1;
}
int main(){
    vector<int>v={10,2,1,3,14,23,12};
    Tree*root=bst(v);
    cout << smallest(root, 7);
    return 0;
}