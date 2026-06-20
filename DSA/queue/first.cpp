#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            data = x;
            next = nullptr;
        }
};
class Queue{
    Node *head;
    Node *tail;
    public:
        Queue(){
            head = tail = nullptr;
        }
        bool empty(){
            return head == nullptr;
        }
        void push(int data){
            Node *newnode = new Node(data);
            if(empty()){
                head =tail= newnode;
                return;
            }else{
                tail->next = newnode;
                tail = newnode;
            }
        }
        void pop(){
            if(empty()){
                cout << "Empty"; 
                return;
            }
            Node *temp = head;
            head = head->next;
            if(head==nullptr){
                tail=nullptr;
                delete temp;
            }
        }
        int front(){
            if(empty()){
                return -1;
            }
            return head->data;
        }
};
int main(){
    Queue q;
    q.push(19);
    q.push(20);
    q.push(30);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    return 0;
}