#include <bits/stdc++.h>
using namespace std;
struct Tree{
    int root;
    Tree *left;
    Tree *right;
    Tree(int val){
        left = right = nullptr;
        root = val;
    }
};
bool check(Tree *p, Tree *q) {
    if(q==nullptr && p==nullptr){
        return true;
    }
    if(!p||!q){
        return false;
    }
    bool leftnode = check(p->left, q->left);
    bool rightnode = check(p->right, q->right);
    return leftnode && rightnode && p->root == q->root;
}
int main()
{
    return 0;
}