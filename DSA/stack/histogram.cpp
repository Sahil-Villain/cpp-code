#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
        int histogram(vector<int>&arr){
            int n = arr.size();
            stack<int> s;
            vector<int> left(n, 0);
            vector<int> right(n, 0);
            //left
            for (int i = 0; i < n;i++){
                while(s.size()>0 && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                left[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
            while(!s.empty()){
                s.pop();
            }
            //right
            for (int i = n-1; i >=0;i--){
                while(s.size()>0 && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                right[i] = s.empty() ? n : s.top();
                s.push(i);
            }
            int maxarea = 0;
            for (int i = 0; i < n;i++){
                int wt = right[i] - left[i] - 1;
                int area = arr[i] * wt;
                maxarea = max(maxarea, area);
            }
            return maxarea;
        }
};
int main(){
    solution obj;
    vector<int> arr = {2, 1, 5, 7, 2, 3};
    // vector<int> rans(arr.size());
    cout << obj.histogram(arr);
    return 0;
}