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
class CircularQueue{
    public:
        Node *head;
        Node *tail;
        CircularQueue(){
            head = tail = nullptr;
        }
        bool isempty(){
            return head == nullptr;
        }
        void insert(int x){
            Node *temp = new Node(x);
            temp->next = nullptr;
            if(head==nullptr){
                head = tail = temp;
                tail->next = head;
            }else{
                tail->next = temp;
                tail = temp;
                tail->next = head;
            }
        }
        void pop(){
            if (isempty()){
                cout << "Empty";
                return;
            }
            if(head==tail){
                delete head;
                head = tail = nullptr;
            }else{
                Node*temp=head;
                head = head->next;
                tail->next=head;
                delete temp;
            }
        }
        int front(){
            if(isempty()){
                return -1;
            }
            return head->data;
        }
        void print(){
            Node *temp = head;
            do{
                if(isempty()){
                    cout << "Empty";
                }
                cout<<temp->data<<"<-";
                temp = temp->next;
            } while (temp != head);
        }
};
int main(){
    CircularQueue obj;
    obj.insert(10);
    obj.insert(11);
    obj.insert(12);
    obj.insert(13);
    obj.insert(14);
    obj.insert(15);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.print();
    return 0;
}