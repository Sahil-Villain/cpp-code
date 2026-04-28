#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sum(vector<int>&val){
    int n = val.size();
    vector<vector<int>> ans;
    set<vector<int>> s;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if(val[i]+val[j]+val[k]==0){
                    vector<int> temp = {val[i], val[j], val[k]};
                    sort(temp.begin(), temp.end());
                    if(s.find(temp)==s.end()){
                        s.insert(temp);
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){ 
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sum(num);
    for(const auto&i:result){
        for(int j:i){
            cout << j<<" ";
        }
        cout << "\n";
    }
    return 0;
}

