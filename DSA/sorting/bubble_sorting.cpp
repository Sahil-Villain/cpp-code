#include <iostream>
#include <vector>
using namespace std;
// bool sort(vector<int>&val){
//     bool check = false;
//     for (int i = 0; i < val.size(); i++){
//         for (int j = 0; j < val.size() - i - 1; j++){
//             if(val[j]< val[j+1]){
//                 swap(val[j], val[j + 1]);
//                 return true;
//             }
//         }
//     }
//     return check;
// }
vector<int> sort(vector<int>&val){
    for (int i = 0; i < val.size(); i++){
        for (int j = 0; j < val.size() - i - 1; j++){
            if(val[j]< val[j+1]){
                swap(val[j], val[j + 1]);
            }
        }
    }
    return val;
}

int main(){
    vector<int> num = {6,5,4,3,2};
    // for(int i:sort(num)){
    //     cout << i;
    // }
    return 0;
}