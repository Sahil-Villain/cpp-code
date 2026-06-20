#include <bits/stdc++.h>
using namespace std;
int search(vector<vector<int>>&val,int target){
    int n = val[0].size();
    int m = val.size();
    int r = 0, c = n - 1;
    while(r<m && c>=0){
        if(target==val[r][c]){
            return val[r][c];
        }else if(target < val[r][c]){
            c--;
        }else{
            r++;
        }
    }
}
int main(){
    vector<vector<int>> num = {{1, 4, 6, 8}, {2, 5, 8, 9}, {3, 6, 10, 33}}; 
    cout<<search(num, 5);
    return 0;
}