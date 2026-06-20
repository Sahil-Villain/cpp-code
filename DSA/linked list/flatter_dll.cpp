#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) {
        data = x;
        next = bottom = nullptr;
    }
};
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = nullptr;
    return result;
}
Node* flatten(Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next); 
    root = merge(root, root->next);   
    return root;
}
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    Node* flat = flatten(head);
    printList(flat);  // Output: 5 7 8 10 19 20 22 50
}
