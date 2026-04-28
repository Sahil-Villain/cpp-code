#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;  // if list1 is empty, return list2
    if (!list2) return list1;  // if list2 is empty, return list1
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
ListNode*create(vector<int>&arr){
    if(arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < arr.size();i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}
void printlist(ListNode*head){
    while(head){
        cout << head ->val<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> arr = {1, 3, 5};
    vector<int> arr2 = {2,4, 5, 8};
    ListNode *head1 = create(arr);
    ListNode *head2 = create(arr2);
    ListNode *merge = mergeTwoLists(head1, head2);
    printlist(merge);
    return 0;
}
