#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int height(Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursive calls
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height of tree
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Height of Binary Tree: " << height(root);

    return 0;
}
