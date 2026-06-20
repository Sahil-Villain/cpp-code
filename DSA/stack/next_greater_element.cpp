// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> arr = {5, 8, 0, 1, 3};
//     stack<int>S;
//     vector<int> ans(arr.size(),0);
//     for (int i = arr.size() - 1; i >= 0; i--){
//         while(S.size()>0 && S.top()<=arr[i]){
//             S.pop();
//         }
//         if(S.empty()){
//             ans[i] = -1;
//         }else{
//             ans[i] = S.top();
//         }
//         S.push(arr[i]);
//     }
//     for(int val:ans){
//         cout << val << " ";
//     }
//         return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> sub = {4, 1, 2};
    vector<int> arr = {1, 3, 4, 2};
    stack<int> s;
    vector<int> ans;
    unordered_map<int,int> m;
    for (int i = arr.size() - 1; i >= 0; i--){
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            m[arr[i]] = -1;
        }else{
            m[arr[i]] = s.top();
        }
        s.push(arr[i]);
    }
    for (int i = 0; i < sub.size();i++){
        ans.push_back(m[sub[i]]);
    }
    for(int i:ans){
        cout << i << " ";
    }
        return 0;
}