#include <bits/stdc++.h>
using namespace std;
string remove(string val,string part){
    while (val.length() > 0 && val.find(part)<val.length()){
        val.erase(val.find(part), part.length());
    }
    return val;
}
int main(){
    string str = "abcdabcdacabcd";
    string part = "abc";
    cout << remove(str, part);
    return 0;
}