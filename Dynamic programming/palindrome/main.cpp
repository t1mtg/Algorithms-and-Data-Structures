#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long d[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                d[i][j] = 1;
            else if (i > j)
                d[i][j] = 0;

    int INF = 1e9;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j])
                d[i][j] = (d[i][j-1] + d[i+1][j] - d[i+1][j-1]) % INF;
            else
                d[i][j] = (d[i+1][j] + d[i][j-1] + 1) % INF;
        }
    }

    cout << (d[0][n-1] + INF) % INF;
    return 0;
}