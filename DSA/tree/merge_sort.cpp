#include<iostream>
#include<vector>
using namespace std;
void  merge(vector<int>&arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1;i++)
        a[i] = arr[left+i];
    for (int j = 0; j < n2;j++)
        b[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }
    }
    while(i<n1)
        arr[k++] = a[i++];
    while(j<n2)
        arr[k++] = b[j++];
}
void mergesort(vector<int>&arr,int left,int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid - 1);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int main(){
    vector<int> v = {2, 4, 3, 1, 5};
    mergesort(v, 0, 4);
    for(int i:v){
        cout << i << " ";
    }
    return 0;
}