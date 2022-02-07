#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> adj_list[100001];
char color[100001];
bool check = true;

void dfs(int v, char clr) {
    color[v] = clr;
    for (int i = 0; i < adj_list[v].size(); i++) {
        int next_vert = adj_list[v][i];
        if (color[next_vert] == 'w') {
            if (clr == 'r') {
                dfs(next_vert, 'b');
            }
            if (clr == 'b') {
                dfs(next_vert, 'r');
            }
        } else if (color[next_vert] == clr) {
            check = false;
        }
    }
}


int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x != y) {
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        } else {
            adj_list[x].push_back(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs(i, 'r');
        }
    }
    if (check) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
