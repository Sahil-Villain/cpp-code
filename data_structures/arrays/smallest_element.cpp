#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {13, 5, 6, 8, 9};
    int smallest  = arr[0];
    int largest  =arr[0];
    for (int i = 0; i < 5; i++){
        // if(arr[i]<smallest){
        //     smallest = arr[i];
        // }
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }
    cout << smallest<<endl;
    cout << largest;
    return 0;
}