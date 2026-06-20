// #include <bits/stdc++.h>
// using namespace std;
// int stock(vector<int>&val){
//     int prof = INT_MIN;
//     for (int i = 0; i < val.size() - 1; i++){
//         for (int j = i + 1; j < val.size(); j++){
//             prof = max(prof,val[j]-val[i]);
//         }
//     }
//     return prof;
// }
// int main()
// {
//     vector<int> num = {7, 1, 5, 3, 6, 4};
//     cout << stock(num);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int stock(vector<int> &val)
{
    int bestbuy = val[0];
    int prof = 0;
    for (int i = 1; i < val.size(); i++)
    {
        if (val[i] > bestbuy)
        {
            prof = max(prof, val[i] - bestbuy);
        }
        bestbuy = min(bestbuy, val[i]);
    }
    return prof;
} 
int main()
{
    vector<int> num = {7, 1, 5, 3, 6,20, 4};
    cout << stock(num);
    return 0;
}