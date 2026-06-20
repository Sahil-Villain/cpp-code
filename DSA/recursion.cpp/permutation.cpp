#include <bits/stdc++.h>
using namespace std;
void permutation(string s,int l,int r){
    if(l==r)
        cout<< s << "\n";
    else{
        for (int i = l; i <= r; i++){
            swap(s[l], s[i]);
            permutation(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
int main(){
    string str = "123";
    // int n = str.size();
    permutation(str, 0, 2);
    return 0;
}