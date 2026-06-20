// #include <bits/stdc++.h>
// using namespace std;
// int product(vector<int>val){
//     int x=1,pro;

//     for (int i = 0; i < val.size(); i++){
//         x *= val[i];
//     }
//     for (int i = 0; i < val.size(); i++){
//         val[i] = x / val[i];

//     }
//     for(int i:val){
//         cout << i<<" ";
//     }
// }
// int main()
// {
//     vector<int> value = {1, 2, 3, 4};

//     product(value);
//     return 0;
// }

// optimaml code

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> product(vector<int>&val){
//     vector<int> prefix;
//     vector<int> suffix;
//     int n = val.size();
//     suffix[n-1] = 1;
//     for (int i = 1; i < 4; i++){
//         prefix[i] = prefix[i - 1] * val[i-1];
//     }
//     for (int i = 2; i >= 0; i--){
//         suffix[i] = suffix[i + 1] * val[i+1];
//     }
//     for (int i = 0; i < 4; i++){
//         val[i] = prefix[i] * suffix[i];
//         // cout << val[i] << " ";
//     }
//     return val;
// }
// int main()
// {
//     vector<int> value = {1, 2, 3, 4};
//     vector<int> result=product(value);
//     for(int i:result){
//         cout << i << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> product(vector<int> &val)
// {
//     vector<int> answ;
//     int ans = 1;
//     for (int i = 0; i < val.size(); i++)
//     {
//         ans *= val[i];
//     }
//     for (int i : val)
//     {
//         answ.push_back(ans / i);
//     }
//     return answ;
// }
// int main()
// {
//     vector<int> num = {1, 2, 3, 4};
//     vector<int> pro = product(num);
//     for (int i : product(num))
//     {
//         cout << i<<" ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> product(vector<int>&val){
//     int n = val.size();
//     vector<int> ans(n,1);
//     vector<int> preffix(n, 1);
//     vector<int> suffix(n, 1);
//     for (int i = 1; i < n;i++){
//         preffix[i] = preffix[i - 1] * val[i - 1];
//     }
//     for (int i = n - 2; i >= 0; i--){
//         suffix[i] = suffix[i + 1] * val[i + 1];
//     }
//     for (int i = 0; i < n; i++){
//         ans[i] = preffix[i] * suffix[i];
//     }
//     return ans;
// }
// int main()
// {
//     vector<int>num={1,2,3,4};
//     for(int i:product(num)){
//         cout << i << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int>product(vector<int>&val){
    int n = val.size();
    vector<int> ans(n, 1);
    int suffix = 1;
    for (int i = 1; i < n; i++){
        ans[i] = ans[i  - 1] * val[i - 1];
    }
    for (int i = n - 2; i >= 0; i--){
        suffix *= val[i + 1];
        ans[i] *= suffix;
    }
    return ans;
}
int main()
{
    vector<int> num = {1, 2, 3, 4};
    for(int i:product(num)){
        cout << i << " ";
    }
    return 0;
}