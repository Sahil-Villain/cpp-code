// #include <iostream>
// #include <vector>
// using namespace std;
// int single(vector<int>&val){
//     int ans = 0;
//     for (int i:val){
//         ans ^= i ;
//     }
//     return ans;
// }
// int main(){
//     vector<int> num = {1, 2, 2, 3, 3, 4, 4, 5, 5};
//     int i=single(num);
//     string a= i==1 ? "yes" : "not";
//     cout << a;
//     return 0; 
// }
#include <iostream>
#include <vector>
using namespace std;
int single(vector<int>&val){
    int st = 0;
    int end = val.size() - 1;
    int mid;
    while(st<=end){
        mid = st + (end - st) / 2;
        if(val[mid]!=val[mid-1] && val[mid]!=val[mid+1]){
            return val[mid];
        }
        else if(mid%2==0){
            if(val[mid]==val[mid-1]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        else{
            if(val[mid]==val[mid-1]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
}
int main(){
    vector<int> num = {1,5, 5, 6, 6};
    cout << single(num);
    return 0;
}