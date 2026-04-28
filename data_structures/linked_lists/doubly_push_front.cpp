#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class dll{
    Node *head;
    Node *tail;
    public:
        dll(){
            head = tail = nullptr;
        }
        void push_front(int val){
            Node *newNode = new Node(val);
            if (!head){
                head = tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        void print(){
            Node *temp = head;
            while(temp!=nullptr){
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
};
int main(){
    dll obj;
    obj.push_front(1);
    obj.push_front(12);
    obj.push_front(14);
    obj.push_front(15);
    obj.push_front(18);
    obj.push_front(19);
    obj.push_front(11);
    obj.print();
    return 0;
}
