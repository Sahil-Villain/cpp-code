#include <bits/stdc++.h>
using namespace std;
int search(int arr[],int target,int st,int end){
    int mid = st + (end - st) / 2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        return search(arr, target, mid + 1, end);
    }
    else{
        return search(arr, target, st, mid - 1);
    }
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    cout << search(arr, 4, 0, 5);
    return 0;
}
