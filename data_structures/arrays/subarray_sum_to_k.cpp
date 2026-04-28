#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // sum 0 exists once initially
    int currentSum = 0, count = 0;

    for (int num : nums) {
        currentSum += num;
        if (prefixCount.find(currentSum - k) != prefixCount.end()) {
            count += prefixCount[currentSum - k];
        }
        prefixCount[currentSum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << "Count of subarrays with sum " << k << " = " 
         << subarraySum(nums, k) << endl;
    return 0;
}
