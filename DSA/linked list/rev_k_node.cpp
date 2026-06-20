// #include <bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node *next;
//     Node(int val){
//         this->data=val;
//         this->next = nullptr;
//     }
// };
// class Knode{
//     Node *head;
//     Node *tail;

// public:
//     Knode(){
//         head = tail = nullptr;
//     }
// };
// int main(){
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        ListNode* end = head;

        while (true) {
            // Move 'end' k steps ahead
            for (int i = 0; i < k && end; i++)
                end = end->next;

            // If less than k nodes remain, break
            if (!end && k > 1) break;

            // Reverse k nodes
            ListNode* start = prevGroup->next;
            ListNode* curr = start->next;
            while (curr != end) {
                start->next = curr->next;
                curr->next = prevGroup->next;
                prevGroup->next = curr;
                curr = start->next;
            }

            // Move prevGroup forward
            prevGroup = start;
        }

        return dummy.next;
    }
};

// Helper functions for testing
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5,10 ,7,8,9};
    ListNode* head = createList(arr);
    Solution sol;
    head = sol.reverseKGroup(head, 4);
    printList(head);
    return 0;
}
