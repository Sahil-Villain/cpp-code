#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
};
void traverse(Node *head){
    while(head!=nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
vector<Node*>merge(Node*head1,Node*head2){
    Node *curr1 = head1;
    Node *curr2 = head2;
    while(curr1!=NULL && curr2!=NULL){
        Node *ptr1 = curr1->next;
        Node *ptr2 = curr2->next;
        curr2->next = curr1->next;
        curr1->next = curr2->next;
        curr1 = ptr1;
        curr2 = ptr2;
    }
    return {head1, curr2};
}
int main(){
    Node *head = new Node(22);
    head->next = new Node(33);
    head->next->next = new Node(334);
    head->next->next->next = new Node(334);
    Node *head2 = new Node(4);
    head2->next = new Node(3);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(13);
    head2->next->next->next->next = new Node(71);
    head2->next->next->next->next->next = new Node(71);
    vector<Node *> ar = merge(head, head2);
    traverse(ar[3]);
    return 0;
}