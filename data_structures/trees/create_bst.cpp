#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

// Function to create BST from vector
Node* createBST(vector<int>& vec) {
    Node* root = NULL;
    for (int key : vec)
        root = insertNode(root, key);
    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Example usage
int main() {
    vector<int> vec = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node* root = createBST(vec);

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
