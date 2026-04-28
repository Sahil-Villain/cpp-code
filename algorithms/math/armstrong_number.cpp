#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    int ans = n;
    int key=0;
    // int dig;
    while (n != 0){
        int dig = n % 10;
        key += (dig*dig*dig);
        n /= 10;
    }
    return key == ans;
}
int count(int n){
    while(n>0){
        if(check(n)){
            cout << n<<endl;
        }
        n--;
    }
}
int main(){
    int x = 2000;
    // if(check(1634)){
    //     cout << "true";
    // }
    count(x);
    return 0;
}
