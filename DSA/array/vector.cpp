// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> vec(4, 0);
//     for(int i:vec){
//         cout << vec[i] << endl;
//     }
//     return 0;
// }
// //single number
#include <bits/stdc++.h>
using namespace std;
int single(vector<int>&num){
    int x=0;
    for (int i = 0; i < num.size(); i++){
        x ^= num[i];
    }
    return x;
}
int main()
{
    vector<int> val = {1, 2, 4, 2, 1};
    cout << single(val);
    return 0;
}