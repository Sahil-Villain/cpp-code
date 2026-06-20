#include<bits/stdc++.h>
using namespace std;
// vector<int>sort(vector<int>&val){
//     for (int i = 0; i < val.size()-1;i++){
//         for (int j = i + 1; j < val.size(); j++){
//             if(val[i]==val[j]){
//                 continue;
//             }
//             if(val[j]<val[i]){
//                 swap(val[i], val[j]);
//             }
//         }
//     }
//     return val;
// }
// vector<int>sort(vector<int>&val){
//     int zero = 0;
//     int one = 0;
//     int two = 0;
//     vector<int> ans;
//     for (int i = 0; i < val .size(); i++){
//         if(val[i]==0){
//             zero++;
//         }else if(val[i]==1){
//             one++;
//         }else{
//             two++;
//         }
//     }
//     for (int i = 0; i < zero; i++){
//         ans.push_back(0);
//     }
//     for (int i = 0; i < one; i++){
//         ans.push_back(1);
//     }
//     for (int i = 0; i < two; i++){
//         ans.push_back(2);
//     }
//     return ans;
// }
vector<int>sort(vector<int>&val){
    int mid = 0, low = 0, high = val.size()-1;
    while(mid<=high){
        if(val[mid]==0){
            swap(val[mid], val[low]);
            low++;
            mid++;
        }
        else if(val[mid]==1){ 
            mid++;
        }
        else{
            swap(val[mid], val[high]);
            high--;
        }
    }
    return val;
}
int main(){
    vector<int> num = {2,0,1,0,2,1,0,2,1,0,1,2};

    // sort(num.begin(), num.end());
    for(int i:sort(num)){ 
        cout << i << " ";
    }
    return 0;
}