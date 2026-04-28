#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};
class List{
    Node *head;
    Node *tail;
    public:
        List(){
            head = tail = nullptr;
        }
        void input(vector<int>&arr){
            if(arr.empty()){
                return;
            }
            head = new Node(arr[0]);
            tail = head;
            Node *temp=head;
            for (size_t i = 1; i < arr.size();i++){
                temp->next = new Node(arr[i]);
                tail = temp->next;
                temp = temp->next;
            }
            tail->next = head;
        }
        void delhead(){
            if(head==tail){
                delete head;
            }else{
                Node *temp = head;
                head = head->next;
                tail->next = head;
                temp->next = nullptr;
                delete temp;
            }
        }
        void print(){
            Node *temp = head->next;
            cout << head->data<<"->";
            while(temp!=head){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "null";
        }
};

int main(){
    List obj;
    vector<int> lists = {1, 2, 3, 4, 5};
    obj.input(lists);
    obj.delhead();
    obj.delhead();
    obj.delhead();
    obj.print();

    return 0;
}
