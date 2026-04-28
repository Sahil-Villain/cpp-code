#include <bits/stdc++.h>
using namespace std;
vector<string> generateGrayCode(int n) {
    if (n == 0) return {"0"};
    if (n == 1) return {"0", "1"};
    vector<string> prev = generateGrayCode(n - 1);
    vector<string> result;

    // Prefix '0' to first half
    for (int i = 0; i < prev.size(); i++) {
        result.push_back("0" + prev[i]);
    }

    // Prefix '1' to reversed second half
    for (int i = prev.size() - 1; i >= 0; i--) {
        result.push_back("1" + prev[i]);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    vector<string> grayCodes = generateGrayCode(n);

    cout << n << "-bit Gray Code sequence:\n";
    for (auto code : grayCodes) {
        cout << code << "\n";
    }

    return 0;
}
