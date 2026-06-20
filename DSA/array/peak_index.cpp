#include <iostream>
#include <vector>
using namespace std;
int peak(vector<int>&val){
    int st = 1;
    int end = val.size()-1;
    int mid;
    while(st<=end){
        mid = st + (end - st) / 2;
        if(val[mid]>val[mid-1] && val[mid]>val[mid+1]){
            return val[mid];
        }
        else if(val[mid]>val[mid-1]){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
}
int main(){
    vector<int> num = {1,2,3, 8, 9, 5, 2};
    cout << peak(num);
    return 0;
}