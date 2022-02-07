#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100001
using namespace std;


int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    int n;
    cin >> n;
    int matrix[n+1][n+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<pair <int, pair <int, int>>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] < INF)
                edges.emplace_back(matrix[i][j], make_pair(i, j));
        }
    }
    int dist[n + 1];
    int parent[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    int v;
    for (int i = 0; i < n; i++) {
        v = -1;
        for (auto e : edges) {
            if (dist[e.second.second] > dist[e.second.first] + e.first) {
                dist[e.second.second] = max(-INF, dist[e.second.first] + e.first);
                parent[e.second.second] = e.second.first;
                v = e.second.second;
            }
        }
    }
        if (v == -1) {
            cout << "NO";
    }
    else {
        vector <int> path;
        for (int i = 0; i < n; i++)
            v = parent[v];
        for (int i = v; i != 0; i = parent[i]) {
            path.push_back(i);
            if (i == v && path.size() > 1)
                break;
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (auto i : path)
            cout << i << " ";
    }
    return 0;
}