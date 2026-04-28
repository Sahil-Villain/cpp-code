#include <bits/stdc++.h>
using namespace std;
void reverse(string &val, int n)
{
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        swap(val[st], val[end]);
        st++;
        end--;
    }
}
int main()
{
    string str = "hello world";
    reverse(str, 11);
    cout << str;
    return 0;
}
