#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node*create(vector<int>&arr){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(size_t i=1;i<arr.size();i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
void printlist(Node*head){
    while(head){
        cout << head->data<<"->";
        head = head->next;
    }

}
int main(){
    // vector<int> list = {1, 2, 3, 4, 5};

    // Node *head = create(list);
    Node *head = new Node(23);
    head->next = new Node(33);
    head->next->next = new Node(339);
    printlist(head);
    // while(head){
    //     cout << head->data<<"->";
    //     head = head->next;
    // }
    // cout << head->data;
    return 0;
}