#include <iostream>
#include <vector>
using namespace std;
int components[100001];
bool used[100001];
vector <int> adj_list[100001];

void dfs(int v, int size) {
    used[v] = 1;
    components[v] = size;
    for (int i = 0; i < adj_list[v].size(); i++) {
        int next_vert = adj_list[v][i];
        if (!used[next_vert]) {
            dfs(next_vert, size);
        }
    }
}


int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
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
        used[i] = 0;
    }

    int size = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, size);
            size++;
        }
    }
    cout << size - 1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << components[i] << " ";
    }

    return 0;
}