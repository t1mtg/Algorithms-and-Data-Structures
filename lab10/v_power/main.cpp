#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> top;
vector <int> adj_list[100001];
bool used[100001];


void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < adj_list[v].size(); i++) {
        int next_vert = adj_list[v][i];
        if (!used[next_vert]) {
            dfs(next_vert);
        }
    }
    top.push_back(v);
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cout << adj_list[i].size() << " ";
    }
    return 0;
}