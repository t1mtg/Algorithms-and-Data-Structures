#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000

int main() {
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair <pair <int, int>, int>> edges;
    for (int j = 1; j <= m; j++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.emplace_back(make_pair(u, v), weight);
    }
    int matrix[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = INF;
        }
    }
    for (auto e : edges) {
        matrix[e.first.first][e.first.second] = e.second;
    }

    for (int i = 1; i <= n; i++) {
        matrix[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
