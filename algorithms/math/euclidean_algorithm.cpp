#include <bits/stdc++.h>
using namespace std;
int euclid(int a,int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    if(a<b){
        return euclid(a, b - a);
    }
    if(a>b){
        return euclid(a - b, b);
    }
}
int main(){
    cout << euclid(20, 25);
    return 0;
}
