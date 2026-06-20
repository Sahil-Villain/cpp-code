// pair sum

// #include <bits/stdc++.h>
// using namespace std;
// vector<int>ps(vector<int>&num,int target){
//     vector<int> ans;
//     for (int i = 0; i < num.size() - 1; i++){
//         for (int j = i + 1; j < num.size();j++){
//             if(num[i]+num[j]==target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
// }
// int main()
// {
//     vector<int> val = {1, 2, 3, 4, 5, 6};
//     vector<int> ans = ps(val, 9);
//     cout << ans[0] << " " << ans[1];
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> ps(vector<int>&num,int target){
    int i = 0,j=num.size()-1;
    vector<int> ans;
    while(i<j){
        if(num[i]+num[j]<target){
            i++;
        }
        else if(num[i]+num[j]>target){
            j--;
        }
        else{
            ans.push_back(num[i]);
            ans.push_back(num[j]);
            return ans;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> val = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ans = ps(val, n);
    cout << ans[0] << " " << ans[1];
    return 0;
}