#include <bits/stdc++.h>
using namespace std;

int stairRec(int n, int level = 1) {
    if (n < level) {
        return level - 1; // previous level was the last full stair
    }
    return stairRec(n - level, level + 1);
}

int main() {
    cout << stairRec(100);
    return 0;
}
