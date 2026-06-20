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
void topview(Tree*root){
    if (!root) return;
    map<int, int> mp;
    queue<pair<Tree*, int>> q;
    q.push({root, 0});
    while(q.size()>0){
        Tree*curr=q.front().first;
        int hd=q.front().second;
        q.pop();
        if(mp.find(hd)==mp.end()){
            mp[hd]=curr->data;
        }
        if(curr->left!=nullptr){
            q.push({curr->left,hd-1});
        }
        if(curr->right!=nullptr){
            q.push({curr->right,hd+1});
        }
    }
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}
int main(){
    vector<int>v={1,2,3,-1,4,-1,5};
    Tree*root=buildtree(v);
    topview(root);
    return 0;
}