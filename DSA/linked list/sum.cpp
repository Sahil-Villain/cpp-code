#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int val){
            this->data=val;
            this->next = nullptr;
        }
};
int sum(node*head){
    int sum = 0;
    while(head){
        sum += head->data;
        head = head->next;
    }
    return sum;
}
int main(){
    node *head = new node(19);
    head->next = new node(44);
    head->next->next = new node(44);
    head->next->next->next = new node(44);
    cout << sum(head);
    return 0;
}