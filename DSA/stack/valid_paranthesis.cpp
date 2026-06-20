#include <bits/stdc++.h>
using namespace std;
int main(){
    // stack<int> st;
    // st.push(3);
    // st.push(1);
    // st.push(1);
    // st.push(1);
    // st.push(1);
    // st.push(55);
    // while(!st.empty()){
    //     cout << st.top()<<" "   ;
    //     st.pop();
    // }
    int arr[3] = {1, 2, 3};
    int k = 0;
    for (int i = 0; i < 3;i++){
        k = k * 10 + arr[i];
    }
    ++k;
    return 0;
}