#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* constructBST(vector<int>& pre, int& index, int min, int max) {
    if (index >= pre.size())
        return NULL;

    Node* root = NULL;
    if (pre[index] > min && pre[index] < max) {
        root = createNode(pre[index]);
        index++;

        root->left = constructBST(pre, index, min, root->key);
        root->right = constructBST(pre, index, root->key, max);
    }

    return root;
}

void printInorder(Node* root) {
    if (root) {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

int main() {
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    int index = 0;

    Node* root = constructBST(pre, index, INT_MIN, INT_MAX);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
