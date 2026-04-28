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
class circular{
    Node *head;
    Node *tail;
    public:
        circular(){
            head = tail = nullptr;
        }
        void insertathead(int val){
            Node *newnode = new Node(val);
            if(tail==nullptr){
                head = tail = newnode;
                tail->next = head;
            }else{
                newnode->next = head;
                head = newnode;
                tail->next = head;
            }
        }
        void print(){
            if(head==nullptr){
                return;
            }
            cout << head->data<<"->";
            Node *temp = head->next;
            while(temp!=head){
                cout << temp->data << " ->";
                temp = temp->next;
            }
            cout << "(head again)\n";
        }

};
int main(){
    circular obj;
    obj.insertathead(1);
    obj.insertathead(2);
    obj.insertathead(3);
    obj.print();
    return 0;
}
