#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        // Traverse both lists
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a; // Intersection node or nullptr
    }
};

// Helper function to print the list from given node
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Example to create and test intersection
int main() {
    // Create nodes for List A
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);

    // Create nodes for List B
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);

    // Common part
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);

    // Connect List A
    a1->next = a2;
    a2->next = c1;

    // Connect List B
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    // Connect common part
    c1->next = c2;
    c2->next = c3;

    Solution sol;

    cout << "List A: ";
    printList(a1);
    cout << "List B: ";
    printList(b1);

    ListNode* intersection = sol.getIntersectionNode(a1, b1);

    if (intersection)
        cout << "\nIntersection Node Value: " << intersection->val << endl;
    else
        cout << "\nNo Intersection Found" << endl;

    return 0;
}
