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
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());
    bool check;
    for (int i = 0; i < top.size() - 1; i++) {
        check = false;
        for (int j = 0; j < adj_list[top[i]].size(); j++) {
            if (adj_list[top[i]][j] == top[i  + 1]) {
                check = true;
            }
        }
        if (!check) {
            break;
        }

    }

    if (check) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
