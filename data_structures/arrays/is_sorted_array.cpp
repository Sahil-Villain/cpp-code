#include <bits/stdc++.h>
using namespace std;
bool check(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n - 1] >= arr[n-2] && check(arr, n - 1);
}
int main(){
    int arr[5] = {1, 2, 4, 13, 15};
    if(check(arr,5)){
        cout << "yes";
    }
    return 0;
}
