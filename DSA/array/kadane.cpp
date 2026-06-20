// #include <bits/stdc++.h>
// using namespace std;
// int kad(vector<int>&num){
//     int x = INT_MIN;
//     for (int i = 0; i < num.size(); i++){
//         int sum = 0;
//         for (int j = i; j < num.size(); j++){
//             sum += num[j];
//             x = max(x, sum);
//         }
//     }
//     return x;
// }
// int main()
// {
//     vector<int> val = {1, -3, 4, 5};
//     cout << kad(val);
//     return 0;
// }

// most optimise
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> val = {1, 2, 3, -4, 5};
//     int maxsum = INT_MIN;
//     int cursum = 0;
//     for (int i = 0; i < val.size(); i++){
//         cursum += val[i];
//         maxsum = max(maxsum, cursum);
//         cursum = cursum > 0 ? cursum : 0;
//     }
//     cout << maxsum;
//     return 0;
// }

// pair sum
#include <bits/stdc++.h>
using namespace std;
void ps(vector<int>&num,int target){
    for (int i = 0; i < num.size()-1; i++){
        for (int j = i + 1; j < num.size(); j++){
            if(num[i]+num[j]==target){
                cout << num[i] << "+" << num[j] << endl;
            }
        }
    }
}
int main()
{
    vector<int> val = {1, 2, 3, 4, 5, 6};
    ps(val, 9);
    return 0;
}