#include <iostream>
#include <vector>
using namespace std;
bool searchInUnsortedMatrix(vector<vector<int>> &mat, int target) {
    for (int i = 0; i < mat.size(); i++) {
        // Traverse all columns
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<int>> mat = {
        {7, 2, 9},
        {4, 1, 5},
        {6, 8, 3}
    };

    int target = 5;

    if (searchInUnsortedMatrix(mat, target)) {
        cout << "Element found in the matrix" << endl;
    } 
    else {
        cout << "Element not found in the matrix" << endl;
    }

    return 0;
}
