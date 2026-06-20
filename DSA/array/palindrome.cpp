#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    int dig, rev;
    int ans = n;
    while(n>0){
        dig = n % 10;
        rev = rev * 10 + dig;
        n /= 10;
    }
    if(ans==rev){
        return true;
    }
}
int main(){
    if(check(123321)){
        cout << "yes";
    }
    return 0;
}