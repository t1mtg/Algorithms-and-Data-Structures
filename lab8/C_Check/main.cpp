#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int matrix[n][n];
    memset(matrix, 0, sizeof(int)*n*n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x-1][y-1] += 1;
    }


    bool check = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((matrix[i][j] == 1 && matrix[j][i] == 1 && (i != j)) || matrix[i][j] > 1 ) {
                check = true;
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
