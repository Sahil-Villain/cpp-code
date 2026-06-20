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
        void pop__back() {
            if (!tail) return; // empty
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr; // list became empty
            }
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
    Node *head = new Node(12);
    head->next = new Node(33);
    head->next->prev = head;
    head->next->next = new Node(233);
    head->next->next->prev = head->next;
    
    Dll obj;
    obj.setHead(head);
    obj.pop__back();
    obj.print();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class Dll {
//     Node *head;
//     Node *tail;
// public:
//     Dll() {
//         head = tail = nullptr;
//     }

//     // helper to set head from outside
//     void setHead(Node* h) {
//         head = h;
//         // find tail
//         Node* temp = head;
//         while (temp && temp->next) temp = temp->next;
//         tail = temp;
//     }
//     void pop__back() {
//         if (!tail) return; // empty
//         Node* temp = tail;
//         tail = tail->prev;
//         if (tail) {
//             tail->next = nullptr;
//         } else {
//             head = nullptr; // list became empty
//         }
//         delete temp;
//     }

//     void print() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL\n";
//     }
// };

// int main() {
//     // manually build nodes
//     Node *head = new Node(12);
//     head->next = new Node(33);
//     head->next->prev = head;
//     head->next->next = new Node(233);
//     head->next->next->prev = head->next;

//     // give to DLL
//     Dll obj;
//     obj.setHead(head);
//     obj.pop__back();
//     cout << "After pop_back:\n";
//     obj.print();

//     return 0;
// }
