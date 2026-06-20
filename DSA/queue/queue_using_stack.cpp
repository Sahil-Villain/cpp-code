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
class Queue{
    stack<int> s1, s2;
    public:
        void insert(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
            }
        }
};
int main(){
    return 0;
}