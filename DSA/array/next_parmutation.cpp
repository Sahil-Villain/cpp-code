#include <bits/stdc++.h>
using namespace std;
int next(int arr[],int n){
    int piv = 0;
    for (int i = n - 2; i >= 0; i--){
        if(arr[i+1]>arr[i]){
            piv = i;
            break; 
        }
    } 
    for (int i = n - 1; i > piv; i--){
        if(arr[i]>arr[piv]){
            swap(arr[i], arr[piv]);
            break;
        }
    }
    int i = piv + 1;
    int j = n - 1;
    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[5] = {3,2,1};
    next(arr, 3);
    return 0;
}