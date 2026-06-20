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
void travese(Node*head){
    // Node *temp = head;
    while(head!=NULL){
        cout << head->data << endl;
        head = head->next;
    }
}
int main(){
    Node *head = new Node(10);
    head->next = new Node(100);
    head->next->next = new Node(100);
    head->next->next->next = new Node(1000);
    travese(head);
    return 0;
}