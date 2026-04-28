#include <bits/stdc++.h>
using namespace std;
void getans(vector<vector<int>>&mat,int r,int c,vector<string>&ans,string path,vector<vector<bool>>&check){
    int n = mat.size();
    
    if(r<0||c<0 ||r>=n||c>=n||mat[r][c]==0||check[r][c]==true){
        return;
    }
    if (r == n - 1 &&c == n-1){
        ans.push_back(path);
        return;
    }
    check[r][c] = true;
    getans(mat, r, c + 1, ans, path + "R",check);
    getans(mat, r, c - 1, ans, path + "L",check);
    getans(mat, r+1, c, ans, path + "D",check);
    getans(mat, r-1, c, ans, path + "U",check);
    check[r][c] = false;

}
vector<string>find(vector<vector<int>>&mat){
    int n = mat.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> check(n, vector<bool>(n, false));
    getans(mat, 0, 0, ans, path, check);
    return ans;
}
int main(){
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector < string>result = find(mat);
    for(string i:result){
        cout << i << " ";
    }
    return 0;
}
