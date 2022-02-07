#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000

int main() {
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
    int n, m;
    fin >> n >> m;
    vector<vector<pair<int, int>>> adj_list(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        fin >> u >> v >> weight;
        adj_list[u].push_back(make_pair(v, weight));
        adj_list[v].push_back(make_pair(u, weight));
    }

    vector<bool> used(n + 1, false);
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_ = pq.top().first;
        pq.pop();
        if (dist_ > dist[u])
            continue;
        for (int j = 0; j < adj_list[u].size(); j++) {
            int v_ = adj_list[u][j].first;
            int weight = adj_list[u][j].second;
            if (!used[v_] && dist[v_] > dist[u] + weight) {
                dist[v_] = dist[u] + weight;
                pq.push(make_pair(dist[v_], v_));
            }
        }
        used[u] = true;
    }

    for (int i = 1; i <= n; i++) {
        fout << dist[i] << " ";
    }
    return 0;
}
