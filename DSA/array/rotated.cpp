#include <iostream>
#include<vector>
using namespace std;
int rotatedbs(vector<int>&val,int target){
    int st = 0;
    int end = val.size() - 1;
    int mid;
    while(st<end){
        mid = st + (end - st) / 2;
        if(val[mid]==target){
            return mid;
        }
        if(val[st]<=val[mid]){
            if(val[mid]>target && target>=val[st]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }else{
            if (val[mid]>=target && target<=val[end]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
}
int main(){
    vector<int> num = {3, 4, 5, 6,0, 1, 2};
    cout << rotatedbs(num, 1);
    return 0;
}