#include <bits/stdc++.h>
using namespace std;
int countPrime(int n){
    vector<bool> isprime (n + 1, true);
    int count = 0;
    for (int i = 2; i < n; i++){
        if(isprime[i]){
            count++;
            for (int j = i * 2; j < n; j += i){
                isprime[j] = false;
            }
        }
    }
    return count;
}
void prime(int x){
    vector<bool> isprime(x + 1, false);
    for (int i = 2; i < x;i++){
        if(!isprime[i]){
            // cout << i<<endl;
            for (int j = i * 2; j <= x;j+=i){
                isprime[j] = true;
            }
        }
    }
    for (int i = 1; i <= x;i++){
        if(!isprime[i]){
            cout << i << " ";
        }
        // else{
        //     cout << i << " not prime\n";
            
        // }
    }
}
int main(){
    // cout << countPrime(50);
    prime(150);
    return 0;
}