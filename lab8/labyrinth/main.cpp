#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> adj_list[10001];

vector <char> bfs (int n, int m, int start, int destination) {
    vector<int> d(n), p(n);
    vector <bool> used(n);
    queue<int> Q;
    p[start] = -1;
    used[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto V : adj_list[u]) {
            int t = V;
            if (!used[t]) {
                used[t] = true;
                Q.push(V);
                d[V] = d[u] + 1;
                p[t] = u;
            }
        }
    }
    vector <int> path(0);
    if (used[destination]) {
        for (int v = destination; v != -1; v = p[v]) {
            path.push_back(v);
        }
    }

    reverse(path.begin(), path.end());
    vector <char> path2;
    int size = path.size();
    for (int i = 0; i < size - 1; i++) {
        int temp = path[i + 1] - path[i];
        if (temp == 1 && m != 1)
            path2.push_back('R');
        else if (temp == -1)
            path2.push_back('L');
        else if (temp > 0)
            path2.push_back('D');
        else if (temp < 0)
            path2.push_back('U');
    }
    return path2;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    int s = 0;
    cin >> n >> m;
    char matrix[n+2][m+2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            matrix[i][j] = '0';
        }
    }
    int start, destination;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'S') {
                start = (i - 1) * m + j;
            }
            if (matrix[i][j] == 'T') {
                destination = (i - 1) * m + j;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] == '.' || matrix[i][j] == 'S' || matrix[i][j] == 'T' ) {
                s++;
                if (matrix[i][j-1] == '.' || matrix[i][j-1] == 'S' || matrix[i][j-1] == 'T' ) {
                    adj_list[(i - 1) * m + j].push_back((i - 1) * m + (j - 1));
                }
                if (matrix[i][j+1] == '.' || matrix[i][j+1] == 'S' || matrix[i][j+1] == 'T') {
                    adj_list[(i - 1) * m + j].push_back((i - 1) * m + (j + 1));
                }
                if ((matrix[i-1][j] == '.' || matrix[i-1][j] == 'S' || matrix[i-1][j] == 'T') && i != 1) {
                    adj_list[(i - 1) * m + j].push_back((i - 2) * m + j);
                }
                if (matrix[i+1][j] == '.' || matrix[i+1][j] == 'S' || matrix[i+1][j] == 'T') {
                    adj_list[(i - 1) * m + j].push_back(i * m + j);
                }
            }
        }
    }

    vector <char> temp;
    temp = bfs(n*m + 1, m, start, destination);
    if (temp.empty()) {
        cout << -1;
    } else {
        cout << temp.size() << endl;
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i];
        }
    }

    return 0;
}