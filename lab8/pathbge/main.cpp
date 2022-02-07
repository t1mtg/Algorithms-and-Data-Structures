#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> adj_list[100001];
vector <int> bfs (int n) {
    vector <int> d(n+1);
    queue <int> Q;
    for (int i = 0; i <= n; i++) {
        d[i] = n;
    }
    d[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto i : adj_list[u]) {
            if (d[i] == n) {
                d[i] = d[u] + 1;
                Q.push(i);
            }
        }
    }
    return d;

}
int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    vector <int> temp;
    temp = bfs(n);
    for (int i = 1; i <= n; i++) {
        cout << temp[i] << " ";
    }
    return 0;
}
