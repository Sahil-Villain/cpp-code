#include <bits/stdc++.h>
using namespace std;
bool ispallindrome(string &s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int partition(string &s,int i,int j){
    if(i>=j || ispallindrome(s,i,j)){
        return 0;
    }
    int res = INT_MAX;
    for (int k = i; k < j; k++){
        if(ispallindrome(s,i,k)){
        int cuts = 1  + partition(s, k + 1, j);
        res = min(res, cuts);
        }
    }
    return res;
}
int par(string &s){
    return partition(s, 0, s.size() - 1);
}
int main(){
    string s = "geek";
    // cout << partition(s, 0, 4);
    cout << par(s);
    return 0;
}
