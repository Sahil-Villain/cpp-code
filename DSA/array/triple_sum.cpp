// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> sum(vector<int>&val){
//     int n = val.size();
//     vector<vector<int>> ans;
//     set<vector<int>> s;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             for (int k = j + 1; k < n; k++){
//                 if(val[i]+val[j]+val[k]==0){
//                     vector<int> temp = {val[i], val[j], val[k]};
//                     sort(temp.begin(), temp.end());
//                     if(s.find(temp)==s.end()){
//                         s.insert(temp);
//                         ans.push_back(temp);
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }
// int main(){ 
//     vector<int> num = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> result = sum(num);
//     for(const auto&i:result){
//         for(int j:i){
//             cout << j<<" ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }


//by hashing

// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> sum(vector<int>&val){
//     //int tofind;
//     int n = val.size();
//     set<vector<int>> ut;
//     for (int i = 0; i < n; i++){
//         int target = -val[i];
//         set<int> s;
//         for (int j = i + 1; j < n; j++){
//             int tofind = target - val[j];
//             if(s.find(tofind)!=s.end()){
//                 vector<int> temp = {tofind, val[i], val[j]};
//                 sort(temp.begin(), temp.end());
//                 ut.insert(temp);
//                 // cout << tofind << " " << target << " " << val[j];
//             }
//             s.insert(val[j]);
//         }
//     }
//      vector<vector<int>> ans(ut.begin(), ut.end());
//     return ans;
// }
// int main(){
//     vector<int> num={-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> result = sum(num);
//     for(const auto&i:result){
//         for(int j:i){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//two pointer

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