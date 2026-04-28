#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};
Node*rotate(Node*head,int k){
    if(k==0||head==nullptr){
        return head;
    }
    for (int i = 0; i < k; i++){
        Node *curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = nullptr;
    }
    return head;
}
void print(Node*node){
    while(node!=nullptr){
        cout << node->data << "->";
        node = node->next;
    }
}
int main(){
    Node *head = new Node(10);
    head->next = new Node(77);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head = rotate(head, 1);
    print(head);
    return 0;
}
