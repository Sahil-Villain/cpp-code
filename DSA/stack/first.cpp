#include <bits/stdc++.h>
using namespace std;
class Stack{
    vector<int> val;
    public:
    void push(int a){
        val.push_back(a);
    }
    void pop(){
        val.pop_back();
    }
    int top(){
        return val[val.size() - 1];
    }
    bool empty(){
        return val.size() == 0;
    }
};
int main(){
    Stack obj;
    obj.push(12);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    obj.push(2);
    while(!obj.empty()){
        cout << obj.top()<<" ";
        obj.pop();
    }
    return 0;
}