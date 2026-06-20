 #include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[7] = {1,2,3,-4,-5,6,7};
    //subarray
    // for (int i = 0; i < 5; i++){
    //     for (int j = i; j < 5; j++){
    //         for (int k = i; k <= j; k++){
    //             cout << arr[k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    //maximum subarray sum
    // int arr[5] = {9, 4, 3, 6, 1};
    int maximum = INT_MIN;
    for (int i = 0; i < 7; i++){
        int cs = 0;
        for (int j = i; j < 7; j++){
            cs += arr[j];
            maximum = max(cs, maximum);
        }
    }
    cout << maximum;
    return 0;
}