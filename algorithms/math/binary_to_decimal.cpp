#include <bits/stdc++.h>
using namespace std;
int bintodecimal(int value){
    int dec=0, rem, pow = 1;
    while(value>0){
        rem = value % 10;
        dec += rem * pow;
        value /= 10;
        pow *= 2;
    }
    return dec;
}
int main()
{
    cout << bintodecimal(1010);
    return 0;
}