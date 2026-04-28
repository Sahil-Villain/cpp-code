#include <bits/stdc++.h>
using namespace std;
int rowsearch(vector<vector<int>>&arr,int tar,int row){
    int n = arr[0].size();
    int st = 0;
    int end = n - 1;
    while(st<=end){
        int mid = st + (end - st) / 2;
        if(tar==arr[row][mid]){
            return true;
        }
        else if(tar>arr[row][mid]){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return false;
}
int search(vector<vector<int>>&mat,int target){
    int m = mat.size(), n = mat[0].size();
    int st = 0, end = m - 1;
    while(st<=end){
        int mid = st + (end - st) / 2;
        if(target>=mat[mid][0]&&target<=mat[mid][n-1]){
            return rowsearch(mat, target, mid);
        }else if(target>=mat[mid][n-1]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
}
int main(){
    vector<vector<int>>mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    search(mat, 9);
    return 0;
}
