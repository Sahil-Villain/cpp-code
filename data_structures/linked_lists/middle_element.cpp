#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int x){
            this->data = x;
            this->next = nullptr;
        }
};
int getlenght(Node* head){
    int length = 0;
    while(head){
        length++;
        head = head->next;
    }
    return length;
}
int getmiddle(Node* head){
    int lenght = getlenght(head);
    int middle_index = lenght / 2;
    while(middle_index--){
        head = head->next;
    }
    return head->data;
}
int main(){
    Node *head = new Node(10);
    head->next = new Node(100);
    head->next->next = new Node(1000);
    head->next->next->next = new Node(10000);
    head->next->next->next->next = new Node(100000);
    cout << getmiddle(head);
    return 0;
}
