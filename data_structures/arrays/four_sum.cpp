#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> forth(vector<int>&val,int target){
    // set<vector<int>> s;
    int n = val.size();
    sort(val.begin(), val.end());
    // vector<vector<int>> ans;
    set<vector<int>> s;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int p = j + 1;
            int q = n - 1;
            while(p<q){
                long long int sum = (long long)val[i] + (long long)val[j] + (long long)val[p] + (long long)val[q];
                if(sum<target){
                    p++;
                }
                else if(sum>target){
                    q--;
                }
                else{
                    // ans.push_back({val[i], val[j], val[p], val[q]});
                    vector<int> temp = {val[i], val[j], val[p], val[q]};
                    s.insert(temp);
                    // ans.push_back(temp);
                    // sort(s.begin(), s.end());
                    p++;
                    q--;
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
int main(){
    vector<int> num = {-2, -1, -1, 1, 1, 2, 2};
    vector<vector<int>>result=forth(num,0);
    for(const auto&i:result){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
