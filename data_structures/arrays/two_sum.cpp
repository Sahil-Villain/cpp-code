#include <bits/stdc++.h>
using namespace std;
vector<int> sum(vector<int>&val,int target){
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < val.size(); i++){
        int first = val[i];
        int sec = target - first;
        if(m.find(sec)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }
    return ans;
}
int main(){
    vector<int> num = {5, 2, 11, 7, 15};
    for(int i:sum(num,9)){
        cout << i<<" ";
    }
    return 0;
}
