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
Tree *first = nullptr, *middle = nullptr, *last = nullptr, *pre = nullptr;
void recover(Tree*root){
    if(!root){
        return;
    }
    recover(root->left);
    if(pre&&root->data<pre->data){
        if(!first){
            first=pre;
            middle = root;
        }else{
            last = root;
        }

    }
    pre = root;
    recover(root->right);
}
void recoverBST(Tree* root) {
    recover(root);

    if (first && last)
        swap(first->data, last->data);
    else if (first && middle)
        swap(first->data, middle->data);
}
void printInorder(Tree* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main(){
    /*
        Example BST (wrong):
                6
               / \
             10   2
             / \  /
            1   3 7
    */
    Tree* root = new Tree(6);
    root->left = new Tree(10);
    root->right = new Tree(2);
    root->left->left = new Tree(1);
    root->left->right = new Tree(3);
    root->right->left = new Tree(7);
    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    recoverBST(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;
    return 0;
}