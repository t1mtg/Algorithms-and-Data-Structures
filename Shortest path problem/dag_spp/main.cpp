#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
long long INF = 2 * 1e18;
using namespace std;

void dfs(long long v, vector<vector<pair<long long, long long>>> &adj_list, long long * &used) {
    used[v] = true;
    for (int i = 0; i < adj_list[v].size(); i++) {
        int to = adj_list[v][i].first;
        if (!used[to])
            dfs(to, adj_list, used);
    }
}

int main() {
    ifstream fin("path.in");
    ofstream fout("path.out");
    long long n, m, s;
    fin >> n >> m >> s;
    vector<vector<pair<long long, long long>>> adj_list(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long weight;
        fin >> u >> v >> weight;
        adj_list[u].push_back(make_pair(v, weight));
    }
    auto *dist = new long long[n + 1];
    auto *used = new long long[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < adj_list[j].size(); k++) {
                long long to = adj_list[j][k].first;
                long long weight = adj_list[j][k].second;
                if ((dist[j] < INF) && (dist[to] > dist[j] + weight)) {
                    dist[to] = max(-INF, dist[j] + weight);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            long long to = adj_list[i][j].first;
            long long weight = adj_list[i][j].second;
            if ((dist[i] < INF) && (dist[to] > dist[i] + weight) && !used[to]) {
                dfs(to, adj_list, used);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            fout << '*' << endl;
        else if (used[i])
            fout << '-' << endl;
        else
            fout << dist[i] << endl;
    }
    delete [] used;
    delete [] dist;
    return 0;
}