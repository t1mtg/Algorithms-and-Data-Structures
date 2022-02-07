#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector <int> adj_list[100001];
bool used[100001];
bool win_vert[100001];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int m, n, pos;
    cin >> n >> m >> pos;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        used[i] = false;
        win_vert[i] = false;
    }

    stack <int> s;
    s.push(pos);

    int cur;
    while (!s.empty()) {
        cur = s.top();
        if (used[cur]) {
            for (auto v : adj_list[cur]) {
                if (!win_vert[v]) {
                    win_vert[cur] = true;
                }
            }
            s.pop();
        }

        used[cur] = true;
        for (auto v : adj_list[cur]) {
            if (!used[v]) {
                s.push(v);
            }
        }
    }

    if (win_vert[pos]) {
        cout << "First player wins" << endl;
    } else {
        cout << "Second player wins" << endl;
    }
    return 0;
}