#include <bits/stdc++.h>
using namespace std;
bool ispallindrom(string val){
    int st = 0;
    int end = val.length()-1;
    while(st<=end){
        if(islower(val[st])!=islower(val[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
}
int main(){
    string str = "racecar";
    if(ispallindrom(str)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}
