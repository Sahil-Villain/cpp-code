//smallest value
// #include <bits/stdc++.h>
// using namespace std;
// int small(vector<int> &val){
//     int minimum = INT_MAX;
//     for (int i = 0; i < val.size();i++){
//         minimum = min(minimum, val[i]);
//     }
//     return minimum;
// }
// int main()
// {
//     vector<int> val = {10, 5, 3, 6, 4, 9};
//     cout << small(val);
//     return 0;
// }


//linear search

// #include <bits/stdc++.h>
// using namespace std;
// int search(int val[],int size,int target){
//     for (int i = 0; i < size-1; i++){
//         if(val[i]==target){
//             return i;
//         }
//     }
// }
// int main()
// {
//     int arr[6] = {3, 6, 4, 8, 36, 7};
//     cout << search(arr, 6, 8);
//     return 0;
// }

//binary search

// #include <bits/stdc++.h>
// using namespace std;
// int search(int arr[],int size,int target){
//     int st = 0;
//     int end = size-1;
//     while(st<end){
//         int mid = st + (end - st) / 2;
//         if(arr[mid]<target){
//             st = mid + 1;
//         }
//         else if(arr[mid]>target){
//             end = mid - 1;
//         }
//         else{
//             return mid;
//         }
//     }
// }
// int main()
// {
//     int arr[5] = {1, 3, 5, 7, 8};
//     cout << search(arr, 5, 8);
//     return 0;
// }

//reverse array

// #include <bits/stdc++.h>
// using namespace std;
// void swap(int &a,int &b){
//     int temp=a;
//     a = b;
//     b = temp;
// }
// void rev(int arr[],int size){
//     int st = 0;
//     int end = size - 1;
//     while(st<end){
//         swap(arr[st], arr[end]);
//         st++;
//         end--;
//     }
// }
// int main()
// {
//     int arrr[5] = { 2, 3, 4, 5, 6};
//     rev(arrr, 5);
//     for (int i = 0; i < 5; i++){
//         cout << arrr[i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    for (int i = 5; i < 7; i++){
        cout << i << " ";
    }
        return 0;
}