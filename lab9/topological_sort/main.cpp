#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> top;
vector <int> adj_list[100001];
char color[100001];
bool cycle = false;


void dfs(int v) {
    color[v] = 'g';
    for (int i = 0; i < adj_list[v].size(); i++) {
        int next_vert = adj_list[v][i];
        if (color[next_vert] == 'w') {
            dfs(next_vert);
        }
        if (color[next_vert] == 'g') {
            cycle = true;
        }
    }
    color[v] = 'b';
    top.push_back(v);
}


int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());
    if (cycle) {
        cout << -1;
    } else {
        for (int i : top) {
            cout << i << " ";
            }
    }
    return 0;
}
