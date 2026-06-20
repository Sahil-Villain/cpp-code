// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> arr = {2, 1, 5, 7, 2, 3};
//     int wt, ht,ans=0;
//     for (int i = 0; i< arr.size(); i++){
//         wt = 1;
//         ht = arr[i];
//         for (int j = i ; j < arr.size();j++){
//             ht = min(ht, arr[j]);
//             int area = ht * wt;
//             wt++;
//             ans = max(area, ans);
//         }
//     }
//     cout << ans;
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// vector<int> Lsmaller(vector<int>&arr){
//     stack<int> s;
//     vector<int> ans(arr.size(),0);
//     // unordered_map<int, int> m;
//     for (int i = 0; i < arr.size();i++){
//         while(s.size()>0 && s.top()>=arr[i]){
//             s.pop();
//         }
//         if(s.empty()){
//             ans[i] = 0;
//         }else{
//             ans[i] = arr[i];
//         }
//         s.push(arr[i]);
//     }
//     return ans;
// }
// vector<int> rsmaller(vector<int>&arr){
//     stack<int> s;
//     vector<int> ans(arr.size(),0);
    // for (int i = arr.size()-1; i>=0;i--){
    //     while(s.size()>0 && s.top()>=arr[i]){
    //         s.pop();
    //     }
    //     if(s.empty()){
    //         ans[i] = 0;
    //     }else{
    //         ans[i] = arr[i];
    //     }
    //     s.push(arr[i]);
    // }
//     return ans;
// }
// int main(){
//     vector<int> arr = {2, 1, 5, 7, 2, 3};
//     int n = arr.size();
//     stack<int> s;
//     vector<int> left(n, 0);
//     vector<int> right(n, 0);
//     for (int i = n-1; i>=0;i--){
//         while(s.size()>0 && s.top()>=arr[i]){
//             s.pop();
//         }
//         right[i] = s.empty() ? -1 : s.top();
//         s.push(arr[i]);
//     }
//     while(!s.empty()){
//         s.pop();
//     }
//     for (int i = 0; i < n;i++){
//         while(s.size()>0 && s.top()>=arr[i]){
//             s.pop();
//         }
//         left[i] = s.empty() ? -1 : s.top();
//         s.push(arr[i]);
//     }
//     return 0;
// }