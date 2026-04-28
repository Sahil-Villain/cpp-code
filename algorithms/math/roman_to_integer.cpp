#include <bits/stdc++.h>
using namespace std;
int value(char i){
    if(i=='I'){
        return 1;
    }
    if(i=='V'){
        return 5;
    }
    if(i=='X'){
        return 10;
    }
    if(i=='L'){
        return 50;
    }
    if(i=='C'){
        return 100;
    }
    if(i=='D'){
        return 500;
    }
    if(i=='M'){
        return 1000;
    }
}
int rd(string &s){
    int res = 0;
    for (int i = 0; i < s.length();i++){
        int s1 = value(s[i]);
        if(s1<s.length()){
            int s2 = value(s[i + 1]);
            if(s1>=s2){
                res += s1;
            }
            else{
                res += (s2 - s1);
                i++;
            }
        }
        else{
            res += s1;
        }
    }
    return res;
}
int main(){
    string s = "XXIII";
    cout << rd(s);
    return 0;
}
