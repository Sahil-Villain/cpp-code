#include <bits/stdc++.h>
using namespace std;
int product(int arr1[3][3],int arr2[3][3]){
    int mat[3][3]={0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                mat[i][j] += arr1[i][k] * arr2[k][j];
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int mat1[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int mat2[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    product(mat1, mat2);
    return 0;
}