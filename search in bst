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

// Function to search for a node in the BST
bool searchNode(Node* root, int key) {
    if (root == NULL) return false;

    if (key == root->key) return true;
    else if (key < root->key) return searchNode(root->left, key);
    else return searchNode(root->right, key);
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
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;

    int key = 10;
    if (searchNode(root, key))
        cout << "Element " << key << " found in the BST." << endl;
    else
        cout << "Element " << key << " not found in the BST." << endl;

    key = 15;
    if (searchNode(root, key))
        cout << "Element " << key << " found in the BST." << endl;
    else
        cout << "Element " << key << " not found in the BST." << endl;

    return 0;
}
