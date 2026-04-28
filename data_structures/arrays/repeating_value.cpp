#include <bits/stdc++.h>
using namespace std;
vector<int>rep(vector<vector<int>>&val){
    vector<int> ans;
    unordered_set<int> s;
    int n = val.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(s.find(val[i][j])!=s.end()){
                ans.push_back(val[i][j]);
            }
            s.insert(val[i][j]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> num = {
        {1, 2, 3},
        {4, 5, 5},
        {7, 8, 3}};
    for(int i:rep(num)){
        cout << i << " ";
    }
    //rep(num);
    return 0;
}
