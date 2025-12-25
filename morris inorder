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

// Function to convert vector to binary tree
Node* vectorToTree(vector<int>& vec, int index) {
    if (index >= vec.size()) return NULL;

    Node* root = createNode(vec[index]);
    root->left = vectorToTree(vec, 2 * index + 1);
    root->right = vectorToTree(vec, 2 * index + 2);

    return root;
}

// Morris Inorder Traversal
void morrisInorder(Node* root) {
    Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->key << " ";
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                cout << current->key << " ";
                current = current->right;
            }
        }
    }
}

// Example usage
int main() {
    vector<int> vec = {4, 2, 6, 1, 3, 5, 7};
    Node* root = vectorToTree(vec, 0);

    cout << "Inorder traversal: ";
    morrisInorder(root);
    cout << endl;

    return 0;
}
