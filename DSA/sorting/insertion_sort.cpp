#include <iostream>
using namespace std;
int sort(int arr[],int n){
    for (int i = 1; i < n; i++){
        int curr = arr[i];
        int pre = i - 1;
        while(pre>=0 && arr[pre]>curr){
            arr[pre + 1] = arr[pre];
            pre--;
        }
        arr[pre + 1] = curr;
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[5];
    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    sort(arr, 5);
    return 0;
}