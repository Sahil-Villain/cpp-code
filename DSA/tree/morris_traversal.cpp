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
    Tree *root=new Tree(pre[0]);
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
vector<int>Morris(Tree*root){
    vector<int>ans;
    Tree*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        }else{
            Tree*ip=curr->left;
            while(ip->right!=nullptr && ip->right!=curr){
                ip=ip->right;
            }
            if(ip->right==nullptr){
                ip->right=curr;
                curr=curr->left;
            }else{
                ip->right=nullptr;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int>v={1,2,3,-1,-1,4,5,-1,-1,-1,-1};
    Tree*root=buildtree(v);
    for(int i:Morris(root)){
        cout<<i<<" ";
    }
    return 0;
}