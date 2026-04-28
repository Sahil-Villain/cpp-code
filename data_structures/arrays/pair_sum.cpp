#include <bits/stdc++.h>
using namespace std;
vector<int> pair_sum(vector<int> &vec, int target)
{
    vector<int> ans;
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] + vec[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5};
    int target = 9;
    vector<int> ans = pair_sum(num, target);
    // vector<int> vec = {1, 2, 3, 4, 5};
    // int n = vec.size();
    // int target = 9;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if (vec[i] + vec[j] == target)
    //         {
    //             vec.push_back(i);
    //             vec.push_back(j);
    //         }
    //     }
    // }
    cout << ans[0] << "+" << ans[1] << "=" << target - 2;
    return 0;
}