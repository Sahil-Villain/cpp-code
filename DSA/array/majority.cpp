// #include <bits/stdc++.h>
// using namespace std;
// int maj(vector<int>&val){
//     for (int i = 0; i < val.size(); i++){
//         int fre = 0;
//         for (int j = 0; j < val.size(); j++){
//             if(val[i]==val[j]){
//                 fre++;
//             }
//         }
//         if(fre>val.size()/2){
//             return val[i];
//         }
//     }
// }
// int main()
// {
//     vector<int> value = {1, 2, 3, 2, 2, 2, 4, 2, 3};
//     cout << maj(value);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int maj(vector<int>&num){
//     int key = 1;
//     int ans = num[0];
//     for (int i = 1; i < num.size(); i++){
//         if(num[i]==num[i-1]){
//             key++;
//         }
//         else{
//             key = 1;
//             ans = num[i];
//         }
//         if (key > num.size() / 2){
//             return ans;
//         }
//     }
// }
// int main()
// {
//     vector<int> ans = {1,2, 2,2,2, 3, 4};
//     cout << maj(ans);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int maj(vector<int>&num){
    int fre = 0;
    int ans;
    for (int i = 0; i < num.size();i++){
        if(fre==0){
            ans = num[i];
        }
        if(ans==num[i]){
            fre++;
        }
        else{
            fre--;
        }
    }
    return ans;
}
int main()
{
    vector<int> val = {1,9, 1, 1, 1, 1, 1, 1};
    cout << maj(val);
    return 0;
}  