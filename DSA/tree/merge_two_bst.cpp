#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int val) {
        data = val;
        left = right = nullptr;
    }
};

Tree* insert(Tree* root, int key) {
    if (!root) return new Tree(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

Tree* bst(vector<int>& v) {
    Tree* root = nullptr;
    for (int i : v)
        root = insert(root, i);
    return root;
}

// inorder traversal to store elements
void inorder(Tree* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

// merge two sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    return res;
}

// build balanced BST from sorted array
Tree* buildBST(vector<int>& v, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    Tree* root = new Tree(v[mid]);
    root->left = buildBST(v, l, mid - 1);
    root->right = buildBST(v, mid + 1, r);
    return root;
}

// merge two BSTs
Tree* mergeBST(Tree* root1, Tree* root2) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);

    vector<int> merged = mergeArrays(a, b);
    return buildBST(merged, 0, merged.size() - 1);
}

// print inorder (for verification)
void printInorder(Tree* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {10, 22, 13, 42, 35};

    Tree* root1 = bst(v1);
    Tree* root2 = bst(v2);

    Tree* mergedRoot = mergeBST(root1, root2);

    cout << "Inorder of merged BST: ";
    printInorder(mergedRoot);

    return 0;
}
