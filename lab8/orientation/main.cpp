#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    bool check = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((matrix[i][j] != matrix[j][i]) || (i == j && matrix[i][j] != 0)) {
                check = false;
            }
        }
    }
    if (check) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
