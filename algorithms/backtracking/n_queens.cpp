#include <bits/stdc++.h>
using namespace std;
class solution{
    public: 
     bool issafe(int row,int col,vector<string>board,int n){
         int duprow = row;
         int dupcol = col;
         while (row >= 0 && col >= 0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row--;
         }
         col = dupcol;
         row = duprow;
         while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
         }
         row = duprow;
         col = dupcol;
         while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
         }
         return true;
     }
    public: 
     void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++){
            if(issafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '_';
            }
        }
     }
    public:
     vector<vector<string>>solveNqueen(int n){
         vector<vector<string>> ans;
         vector<string> board(n);
         string s(n, '_');
         for (int i = 0; i < n; i++){
             board[i] = s;
         }
         solve(0, board, ans, n);
         return ans;
     }
};
int main(){
    int n = 4;
    solution obj;
    vector<vector<string>> ans=obj.solveNqueen(n);
    for (int i = 0; i < ans.size();i++){
        cout << "arrangement" << i + 1<<endl;
        for (int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j]<<endl;
        }
    }
    return 0;
}


