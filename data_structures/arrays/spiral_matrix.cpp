#include <bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>> &val)
{
    int m = val.size();
    int n = val[0].size();
    int srow = 0, erow = n - 1, scol = 0, ecol = m - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        for (int i = srow; i <= erow; i++)
        {
            ans.push_back(val[srow][i]);
        }
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(val[i][ecol]);
        }
        for (int i = ecol - 1; i >= scol; i--)
        {
            ans.push_back(val[erow][i]);
        }
        for (int i = erow - 1; i > srow; i--)
        {
            ans.push_back(val[i][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}
int main()
{
    vector<vector<int>> num = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    for (int i : spiral(num))
    {
        cout << i << " ";
    }
    return 0;
}
