// #include <bits/stdc++.h>
// using namespace std;
// int stair(int n,int key,int j){
//     if(key==n){
//         return j;
//     }
//     for (int i = 1; i <= n;i++){
//         if(i==key){
//             j++;
//         }
//         stair(n, key + 1, j);
//     }
// }

// int main(){
//     cout << stair(10, 0, 1);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int stair(int n){
//     int stair = 0,key=1;
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= i;j++){
//             if(i==j){
//                 stair++;
//             }
//             if(key==n){
//                 return stair;
//             }
//             key++;
//         }
//     }
// }
// int main(){
//     cout << stair(100);
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int stairRec(int n, int level = 1) {
//     if (n < level) {
//         return level - 1; // previous level was the last full stair
//     }
//     return stairRec(n - level, level + 1);
// }

// int main() {
//     cout << stairRec(15);
//     return 0;
// }