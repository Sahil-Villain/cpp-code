#include <bits/stdc++.h>
using namespace std;
void ss(vector<int>&ans,vector<int>&val,int i){
    set<vector<int>> s;
    if(i==val.size()){
        for(int i:ans){
            cout << i<<" ";
        }
        cout << endl;
        return;
    }
    ans.push_back(val[i]);
    ss(ans, val, i + 1);
    ans.pop_back();
    ss(ans, val, i + 1);
}
int main(){
    vector<int> num = {1, 2, 3};
    vector<int> ans;
    ss(ans, num, 0);
    return 0;
}
