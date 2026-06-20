#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
        vector<int>next(vector<int>&arr){
            stack<int>s;
            int n = arr.size();
            vector<int> ans(n, 0);
            for (int i = 2 * n - 1; i >= 0;i--){
                while(s.size()>0 && arr[s.top()]<=arr[i%n]){
                    s.pop();
                }
                ans[i%n] = s.empty() ? -1 : arr[s.top()];
                s.push(i % n);
            }
            return ans;
        }
};
int main(){
    solution obj;
    vector<int> arr = {5, 8, 0, 1, 3};
    for(int i:obj.next(arr)){
        cout << i << " ";
    }
    return 0;
}