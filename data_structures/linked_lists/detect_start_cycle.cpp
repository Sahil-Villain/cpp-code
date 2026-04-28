#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Detect cycle and return starting node if exists
Node* detectCycleStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect if cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // cycle detected
            // Step 2: Find cycle start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // cycle start node
        }
    }
    return nullptr; // no cycle
}

int main() {
    // Create linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle: connect last node (5) to node (3)
    head->next->next->next->next->next = head->next->next;

    Node* start = detectCycleStart(head);

    if (start != nullptr) {
        cout << "Cycle starts at node with value: " << start->data << endl;
    } else {
        cout << "No cycle found." << endl;
    }

    return 0;
}
