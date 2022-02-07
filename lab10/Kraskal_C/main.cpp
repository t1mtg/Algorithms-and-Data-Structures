#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> components;

int get (int v) {
    if (v == components[v])
        return v;
    else
        return components[v] = get(components[v]);
}

void unite (int u, int v) {
	u = get (u);
	v = get (v);
	if (rand() & 1)
		swap (u, v);
	if (u != v)
		components[u] = v;
}

int main() {
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
	int n, m;
	long long cost = 0;
	cin >> n >> m;
	vector < pair < int, pair<int,int> > > g (m + 1);
	for (int i = 1; i <= m; i++){
		cin >> g[i].second.first >> g[i].second.second >> g[i].first;
	}

	sort (g.begin(), g.end());
	components.resize (n + 1);
	for (int i = 1; i <= n; ++i)
		components[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u = g[i].second.first,  v = g[i].second.second,  weight = g[i].first;
		if (get(u) != get(v)) {
			cost += weight;
			unite (u, v);
		}
	}
	cout << cost;

    return 0;
}
