// #include <bits/stdc++.h>
// using namespace std;
// int container(vector<int>& height){
//     int maxwater = 0;
//     for (int i = 0; i < height.size();i++){
//         for (int j = i + 1; j < height.size();j++){
//             int ht = min(height[i], height[j]);
//             int w = j - i;
//             int wat = ht * w;
//             maxwater = max(wat, maxwater);
//         }
//     }
//     return maxwater;
// }
// int main()
// {
//     vector<int> cont = {1,8,6,2,5,4,8,3,7};
//     cout<<container(cont);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int container(vector<int>cont){
    int maxwater = 0;
    int L = 0, R = cont.size() - 1;
    while(R>L){
        int wt = R - L;
        int ht = min(cont[L], cont[R]);
        int wat = ht * wt;
        cont[L] < cont[R] ? L++ : R--;
        maxwater = max(maxwater, wat);
    }
    return maxwater;
}
int main()
{
    vector<int> Cont = {1,2,3,4};
    cout << container(Cont);
    return 0;
}