#include <bits/stdc++.h>
using namespace std;

void helper(int ind, int r, vector<int>& data, vector<vector<int>>& result, vector<int>& arr) {
    if (data.size() == r) {
        result.push_back(data);
        return;
    }
    int n = arr.size();
    for (int i = ind; i < n; i++) {
        data.push_back(arr[i]);
        helper(i + 1, r, data, result, arr);
        data.pop_back();
    }
}

vector<vector<int>> find(vector<int>& arr, int r) {
    vector<vector<int>> result;
    vector<int> data;
    helper(0, r, data, result, arr);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int r = 2;
    vector<vector<int>> result = find(arr, 3);

    for (const auto& i : result) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
