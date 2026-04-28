#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>triple(vector<int>&val){
    sort(val.begin(), val.end());
    int n = val.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        if(i>0 && val[i]==val[i-1])continue;
        int j = i+1, k = n - 1;
        while(j<k){
            int sum = val[i] + val[k] + val[j];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({val[i], val[j], val[k]});
                while(j<k && val[j]==val[j+1])j++;
                while(j<k && val[k]==val[k-1])k--;
                j++;
                k--;
            }
        }
    }
    // vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
int main(){
    vector<int> num={-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = triple(num);
    for(const auto&i:result){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
