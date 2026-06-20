// #include <bits/stdc++.h>
// using namespace std;
// int bs(vector<int>&val,int target){
//     int st = 0;
//     int n = val.size();
//     int end = n - 1;
//     int mid;
//     while(st<end){
//         mid = st + (end - st) / 2;
//         if(val[mid]>target){
//             end = mid-1;
//         }
//         else if(val[mid]<target){
//             st = mid + 1;
//         } 8
//         else{
//             return mid;
//         }
//     }
// }
// int main()
// {
//     vector<int> num = {1, 2, 3, 4, 5, 6, 7};
//     cout << bs(num, 6);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int bs(vector<int>val,int st,int end,int target){
//     if(st<end){
//         int mid = st + (end - st) / 2;
//         if(val[mid]>target){
//             return bs(val, st, mid - 1, target);
//         }
//         else if(val[mid]<target){
//             return bs(val, mid + 1, end, target);
//         }
//         else{
//             return mid;
//         }
//     }
// }
// int main()
// {
//     vector<int> num = {1, 2, 3, 4, 5, 6, 7};
//     cout << bs(num,0,7, 6);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
vector<int> rev(vector<int>val){
    int st=0;
    int end = val.size() - 1;
    while(st<end){
        swap(val[st], val[end]);
        st++;
        end--;
    }
    return val;
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6};
    for(int i:rev(num)){
        cout << i << " ";
    }
    cout << num[0];
    return 0;
}