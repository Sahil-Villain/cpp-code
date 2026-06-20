#include <bits/stdc++.h>
using namespace std;
int rev(int n){
    int dig;
    int rev=0;
    while(n!=0){
        dig = n % 10;
        rev = rev * 10 + dig;
        n /= 10;
    }
    return rev;
}
int main(){
    cout << rev(4321);
    return 0;
}