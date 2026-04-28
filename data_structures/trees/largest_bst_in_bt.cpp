#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct Info {
    int sz;
    int max;
    int min;
    int ans;
    bool isBST;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Info largestBST(Node* root) {
    Info ret;
    if (root == NULL) {
        ret.sz = 0;
        ret.max = INT_MIN;
        ret.min = INT_MAX;
        ret.ans = 0;
        ret.isBST = true;
        return ret;
    }

    if (root->left == NULL && root->right == NULL) {
        ret.sz = 1;
        ret.max = ret.min = root->key;
        ret.ans = 1;
        ret.isBST = true;
        return ret;
    }

    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    ret.sz = (1 + l.sz + r.sz);
    ret.min = min(l.min, min(r.min, root->key));
    ret.max = max(r.max, max(l.max, root->key));

    if (l.isBST && r.isBST && l.max < root->key && r.min > root->key) {
        ret.ans = ret.sz;
        ret.isBST = true;
    } else {
        ret.ans = max(l.ans, r.ans);
        ret.isBST = false;
    }

    return ret;
}

int main() {
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(60);
    root->left->left = createNode(5);
    root->left->right = createNode(20);
    root->right->left = createNode(45);
    root->right->right = createNode(70);
    root->right->right->left = createNode(65);
    root->right->right->right = createNode(80);

    Info res = largestBST(root);
    cout << "Size of the largest BST: " << res.ans << endl;

    return 0;
}
