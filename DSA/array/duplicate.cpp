#include <bits/stdc++.h>
using namespace std;
int duplicate(vector<vector<int>>&val){
    unordered_set<int> s;
    int n = val.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(s.find(val[i][j])!=s.end()){
                return val[i][j];
            }
            s.insert(val[i][j]);
        }
    }
}
int main(){
    vector<vector<int>>num={
    {1, 2, 3},
        {4, 6, 9},
        {7, 8, 9}};
    cout << duplicate(num);
    return 0;
}