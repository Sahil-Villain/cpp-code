#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ms = INT_MIN;
    int cs = 0;
    int arr[5] = {1, 2, 3, -4, -5};
    for (int i = 0; i < 5; i++){
        cs += arr[i];
        ms = max(cs, ms);
        if(cs<0){
            cs = 0;
        }
    }
    cout << ms;
    return 0;
}