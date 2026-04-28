#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int roman(string s){
    unordered_map<char, int> m = {
        {'I',1}, {'V',5}, { 'X',10}, { 'L',50}, { 'C',100}, { 'D',500}, {'M',1000}};
    int n = s.size();
    int ans = 0;
    for (int i =0; i < n;i++){
        if(m[s[i]]>=m[s[i+1]]){
            ans += m[s[i]];

        }else if(i==n-1){
            ans += m[s[i]];
        }else{
                ans -= m[s[i]];
            }
    }
    return ans;
}
string num(int n){
    vector<pair<int, string>> m = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    string ans = "";
    for(auto &p:m){
        while(p.first<=n){
            ans += p.second;
            n -= p.first;
        }
    }
    return ans;
}
int main(){
    cout << roman("XI");
    cout << endl;
    cout << num(432);
    return 0;
}
