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
bool detect(Node*head){
    Node *slow = head;
    Node *fast = head;
    while(slow||fast){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main(){
    
    return 0;
}