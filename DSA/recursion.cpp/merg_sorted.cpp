#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr, int st,int mid,int end){
    vector<int> temp;
    int i = st, j = mid + 1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++  ;
    }
    for (int ind = 0; ind < temp.size(); ind++){
        arr[ind+st] = temp[ind];
    }
}
void mergesort(vector<int>&ans,int st,int end){
    if(st<end){
        int mid = st + (end - st) / 2;
    mergesort(ans, st, mid);
    mergesort(ans, mid + 1, end);
    merge(ans, st, mid, end);
    }
}
// vector<int>solve(vector<int>&val){
//     vector<int> ans;
//     mergesort(ans,val, 0, val.size());
//     return ans;
// }
int main(){
    vector<int> val = {2, 4, 5, 8, 9, 1};
    mergesort(val, 0, val.size() - 1);
    for(int i:val){
        cout << i << " ";
    }
    return 0;
}