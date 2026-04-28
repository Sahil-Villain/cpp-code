#include <bits/stdc++.h>
using namespace std;
int missing(vector<vector<int>>&val){
    int expsum = 0;
    int miss,a;
    vector<int> ans;
    unordered_set<int> s;
    int n = val.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            expsum += val[i][j];
            if (s.find(val[i][j]) != s.end()){
                a = val[i][j];
            }
            s.insert(val[i][j]);
        }
    }
    return 45+a-expsum;
}
int main(){
    vector<vector<int>> num = {
        {1, 2, 3},
        {4, 6, 9},
        {7, 8, 9}};
    cout << missing(num);
    return 0;
}
