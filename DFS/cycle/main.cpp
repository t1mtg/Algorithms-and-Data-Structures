#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> adj_list[100001];
int parent[100001];
char color[100001];
int start = -1, finish;

bool dfs(int v) {
    color[v] = 'g';
    for (unsigned i = 0; i < adj_list[v].size(); i++) {
        int next_vert = adj_list[v][i];
        if (color[next_vert] == 'w') {
            parent[next_vert] = v;
            if (dfs(next_vert)) {
                return true;
            };
        } else if (color[next_vert] == 'g') {
            start = next_vert;
            finish = v;
            return true;
        }

    }
    color[v] = 'b';
    return false;
}


int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
        parent[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        if (dfs(i)) {
            break;
        }
    }
    //cout << start << " " << finish << endl;
    if (start == -1) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        vector <int> cycle;
        cycle.push_back(start);
        for (int v = finish; v != start; v = parent[v]) {
            cycle.push_back (v);
        }
        reverse(cycle.begin(), cycle.end());
        for (auto i : cycle) {
            cout << i << " ";
        }
    }
    return 0;
}
