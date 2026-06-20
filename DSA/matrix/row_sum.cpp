// #include <bits/stdc++.h>
// using namespace std;
// int sum(int mat[3][3]){
//     int maxsum = INT_MIN;
//     for (int i = 0; i < 3; i++){
//         int sum = 0;
//         for (int j = 0; j < 3; j++){
//             sum += mat[j][i];
//         }
//         maxsum = max(maxsum, sum);
//     }
//     return maxsum;
// }
// int main(){
//     int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     cout << sum(arr);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int diagonal(int mat[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += mat[i][i];
    }
    return sum;
}
int main(){
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << diagonal(arr);
    return 0;
}