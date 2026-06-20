#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int val){
            this->data = val;
            this->next = nullptr;
        }
};
Node* deletenode(Node* head){
    Node *p = head,*p1=head;
    int count = 0;
    while(p!=nullptr){
        count++;
        p = p->next;
    }
    int middle = count / 2;
    for (int i = 0; i < middle - 1;i++){
        p1 = p1->next;
    }
    p1->next = p1->next->next;
    return head;
}
void print(Node*head){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout << "null";
}
int main(){
    Node *head = new Node(12);
    head->next = new Node(77);
    head->next->next = new Node(773);
    head->next->next->next = new Node(7723);
    head->next->next->next->next = new Node(4773);
    head=deletenode(head);
    print(head);
    return 0;
}