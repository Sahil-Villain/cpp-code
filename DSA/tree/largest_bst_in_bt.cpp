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
struct info{
    int sz;
    int min;
    int max;
    int ans;
    bool isbst;
};
info largest(Tree*root){
    info res;
    if(!root){
        res.sz = 0;
        res.min = INT_MAX;
        res.max = INT_MIN;
        res.isbst = true;
        res.ans = 0;
        return res;
    }
    if(!root->left&&!root->right){
        res.sz = 1;
        res.ans = 1;
        res.isbst = true;
        res.min = res.max = root->data;
        return res;
    }
    info l = largest(root->left);
    info r = largest(root->right);
    res.sz = 1 + l.sz + r.sz;
    res.min = min(l.min, min(r.min, root->data));
    res.max = max(r.max, max(l.max, root->data));
    if(l.isbst && r.isbst && l.max<root->data && r.min>root->data){
        res.ans = res.sz;
        res.isbst = true;
    }else{
        res.ans = max(l.ans, r.ans);
        res.isbst = false;
    }
    return res;
}
int main(){
    Tree *root = new Tree(50);
    root->left = new Tree(30);
    root->right = new Tree(59);
    root->left->left = new Tree(5);
    root->left->right = new Tree(20);
    root->right->left = new Tree(45);
    root->right->right = new Tree(75);
    root->right->right->left = new Tree(71);
    root->right->right->right = new Tree(80);
    info res = largest(root);
    cout << res.ans;
    return 0;
}