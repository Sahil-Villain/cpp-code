#include <bits/stdc++.h>
using namespace std;
int merge(int arr[6],int arr2[3]){
    int index = 5, i = 2, j = 2;
    while(i>=0 && j>=0){
        if(arr[i]>arr2[j]){
            arr[index] = arr[i];
            index--;
            i--;
        }
        else{
            arr[index] = arr2[j];
            index--;
            j--;
        }
    }
    for (int i = 0; i < 6; i++){
        cout << arr[i];
    }
}
int main(){
    int arr[6] = {1, 2, 3, 0, 0, 0};
    int arr2[3] = {2, 5, 6};
    merge(arr, arr2);
    return 0;
}
