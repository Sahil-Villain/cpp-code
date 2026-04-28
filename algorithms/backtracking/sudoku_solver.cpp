#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>>&mat,int row,int col,int dig){
    for (int i = 0; i < 9; i++){
        if(mat[row][i]==dig){
            return false;
        }
    }
    for (int i = 0; i < 9; i++){
        if(mat[i][col]==dig){
            return false;
        }
    }
    // int srow = (row / 3) * 3;
    // int scol = (col / 3) * 3;
    // for (int i = srow; i < srow + 2;i++){
    //     for (int j = scol; j < scol + 2; j++){
    //         if(mat[srow][scol]==dig){
    //             return false;
    //         }
    //     }
    // }
    int srow = row - (row % 3);
    int scol = col - (col % 3);
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if(mat[i+srow][j+scol]==dig){
                return false;
            }
        }
    }
        return true;
}
bool ss(vector<vector<int>>&mat,int row,int col){
    if(row==8 && col==9){
        return true;
    }
    if(col==9){
        row++;
        col = 0;
    }
    if(mat[row][col]!=0){
        return ss(mat, row, col + 1);
    }
    for (int dig = 1; dig <= 9;dig++){
        if(issafe(mat,row,col,dig)){
            mat[row][col] = dig;
            if(ss(mat,row,col+1)){
                return true;
            }
            mat[row][col] = 0;
        }

    }
    return false;
}
void sudoku(vector<vector<int>>&mat){
    ss(mat, 0, 0);
}
int main(){
    vector < vector<int>> mat = {{3,0,6,5,7,8,4,0,0},
                                 {5,2,0,0,0,0,0,0,0},
                                 {0,8,7,0,0,0,0,3,1},
                                 {0,0,3,0,1,0,0,8,0},
                                 {9,0,0,8,6,3,0,0,5},
                                 {0,5,0,0,9,0,6,0,0},
                                 {1,3,0,0,0,0,2,5,0},
                                 {0,0,0,0,0,0,0,7,4},
                                 {0,0,5,2,8,6,3,0,0}

    };
    sudoku(mat);
    for (int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++){
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
        return 0;
}
