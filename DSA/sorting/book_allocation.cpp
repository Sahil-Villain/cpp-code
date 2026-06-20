#include <iostream>
#include <vector>
using namespace std;
bool isvalid(vector<int>&arr,int n,int m,int max){
    int stu = 1;
    int pages = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]>max){
            return false; 
        }
        if(pages+arr[i]<=max){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }
    return stu > m ? false : true;
}
int allocation(vector<int>&val,int n,int m){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += val[i];
    }
    int st = 0, end = sum;
    int mid;
    while(st<=end){
        mid = st + (end - st) / 2;
        if(isvalid(val,n,m,mid)){
            sum = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return sum;
}
int main(){
    vector<int> num = {2, 1, 3, 4,5};
    cout << allocation(num, 5, 2);
    return 0;
}