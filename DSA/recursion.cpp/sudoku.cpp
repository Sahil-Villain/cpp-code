// #include <bits/stdc++.h>
// using namespace std;
// bool issafe(vector<vector<char>>&board,int row,int col,int dig){
//     for (int j = 0; j < 9; j++){
//         if(board[row][j]==dig || board[j][col]==dig){
//             return false;
//         }
//     }
//     // grid

//     int srow = (row / 3) * 3;
//     int scol = (col / 3) * 3;
//     for (int i = srow; i < srow + 2; i++){
//         for (int j = scol; j < scol + 2; j++){
//             if(board[i][j]==dig){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool ss(vector<vector<char>>&board,int row,int col){
//     if(row==9){
//         return;
//     }
//     int nextrow = row+1;
//     int nextcol = 0;
//     if(nextcol==9){
//         nextrow = row + 1;
//         nextcol = col;
//     }
//     if(board[row][col]='_'){
//         return ss(board, nextrow, nextcol);
//     }
//     for (char i = '1'; i < '9'; i++){
//         if(issafe(board,row,col,i)){
//             board[row][col] == i;
//             if(ss(board, nextrow, nextcol)){
//                 return true;
//             }
//             board[row][col] = '_';
//         }
//     }
//     return false;
// }
// int main(){
// //     vector < vector<char> board = {{'2', '_', '_', '_', '_', '1', '4', '_', '_'},
// //                                     {'7','_','_','_','9','_','_','_','_',},
// //                                     {'_','3','_','_','5','6','_','_','2'},
// //                                     {'_','7','_','2','1','8','5''_','6'},
// //                                     {'1','_','2','_','_','5','9','3''_'}
// // };
// return 0;
// }


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
    vector < vector<int>> mat = {{3,1,6,0,0,0,0,0,2},
                                 {5,2,0,0,0,0,0,0,0},
                                 {0,8,7,0,0,0,0,3,1},
                                 {0,0,3,0,0,0,0,8,0},
                                 {9,0,0,8,0,3,0,0,5},
                                 {0,5,0,0,0,0,6,0,0},
                                 {1,3,0,0,0,0,2,5,0},
                                 {0,0,0,0,0,0,0,7,4},
                                 {0,0,5,2,0,6,3,1,0}
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