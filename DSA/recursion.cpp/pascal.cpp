#include <iostream>
using namespace std;

// Recursive function to calculate value at given position
int pascalValue(int row, int col) {
    if (col == 0 || col == row)   // base case
        return 1;
    return pascalValue(row - 1, col - 1) + pascalValue(row - 1, col);
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        // spacing for triangle shape
        for (int space = 0; space < n - i - 1; space++) 
            cout << "  ";
        
        // print numbers in row
        for (int j = 0; j <= i; j++) {
            cout << pascalValue(i, j) << "   ";
        }
        cout << endl;
    }

    return 0;
}
