#include <iostream>
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

// Function to delete a node with no child (leaf node)
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
    }
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
    Node* root = createNode(8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);

    cout << "Inorder traversal before deletion: ";
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 1); // Delete leaf node

    cout << "Inorder traversal after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
