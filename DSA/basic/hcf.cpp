// #include <bits/stdc++.h>
// using namespace std;
// int hcf(int a,int b){
//     int ans = min(a, b);
//     while (ans > 1){
//         if(a%ans==0 && b%ans==0){
//             return ans;
//         }
//         ans--;
//     }
// }
// int main(){
//     int x = 20, y =40;
//     cout << hcf(x, y);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int lcm(int a,int b){
//     int ans = max(a, b);
//     while(ans>0){
//         if(ans%a==0 && ans%b==0){
//             return ans;
//         }
//         ans++;
//     }
//     return ans;
// }
// int main(){
//     cout << lcm(25, 30);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int euclid(int a,int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    if(a<b){
        return euclid(a, b - a);
    }
    if(a>b){
        return euclid(a - b, b);
    }
}
int main(){
    cout << euclid(20, 25);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>> &val)
{
    int m = val.size();
    int n = val[0].size();
    int srow = 0, erow = n - 1, scol = 0, ecol = m - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        for (int i = srow; i <= erow; i++)
        {
            ans.push_back(val[srow][i]);
        }
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(val[i][ecol]);
        }
        for (int i = ecol - 1; i >= scol; i--)
        {
            ans.push_back(val[erow][i]);
        }
        for (int i = erow - 1; i > srow; i--)
        {
            ans.push_back(val[i][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}
int main()
{
    vector<vector<int>> num = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    for (int i : spiral(num))
    {
        cout << i << " ";
    }
    return 0;
}