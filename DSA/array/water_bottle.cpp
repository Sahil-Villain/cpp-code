#include <iostream>
using namespace std;
int empty(int n, int e){
    int ans = n;
    int remainder = 0;
    while (n != 0)
    {
        ans += n / e;
        remainder = n % e;
        n = n / e + remainder;
    }
    return ans;
}
int main()
{
    cout << empty(15, 4);
    return 0;
}