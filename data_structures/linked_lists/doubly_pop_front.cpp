#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class Dll{
    Node *head;
    Node *tail;
    public: 
        Dll(){
            head = tail = nullptr;
        };
        void setHead(Node* h) {
        head = h;
        // find tail
        Node* temp = head;
        while (temp && temp->next) temp = temp->next;
        tail = temp;
    }
        void pop__front(){
            Node*temp=head;
            head = head->next;
            if(head!=NULL){
                head->prev = nullptr;
            }
            temp->next = nullptr;
            delete temp;
        }
        void print(){
            while(head){
                cout << head->data<<" ->";
                head = head->next;
            }
        }
};
int main(){
    Dll obj;
    Node *head = new Node(12);
    head->next = new Node(33);
    head->next->next = new Node(233);
    obj.setHead(head);
    obj.pop__front();
    obj.pop__front();
    obj.print();
    return 0;
}
