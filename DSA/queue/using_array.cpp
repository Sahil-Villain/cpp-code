#include <bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int size;
    int first;
    int last;
    public:
        Queue(int s){
            size=s;
            arr = new int[size];
            first = 0;
            last = -1;
        }
        void insert(int x){
            if(isfull()){
                cout << "Overflow";
                return;
            }
            last++;
            arr[last] = x;
        }
        bool isfull(){
            return first == size - 1;
        }
        int front(){
            if(isfull()){
                return -1;
            }
            return arr[first];
        }
        int rear(){
            if(isfull()){
                return -1;
            }
            return arr[last];
        }
        void pop(){
            if(isfull()){
                cout << "Empty";
            }
            first++;
        }
};
int main(){
    Queue obj(5);
    obj.insert(12);
    obj.insert(13);
    obj.insert(14);
    obj.insert(15);
    obj.insert(17);
    obj.insert(19);
    obj.insert(129);
    // cout << obj.front();
    obj.pop();
    cout << obj.front();
    cout << obj.rear();
    return 0;
}