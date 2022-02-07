#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> top;
vector <int> adj_list_1[100001];
vector <int> adj_list_2[100001];
int components[100001];
char color[100001];


void dfs1(int v) {
    color[v] = 'g';
    for (auto i = 0; i < adj_list_1[v].size(); i++) {
        int next_vert = adj_list_1[v][i];
        if (color[next_vert] == 'w') {
            dfs1(next_vert);
        }
    }
    top.push_back(v);
}

void dfs2(int v, int comp_num) {
    color[v] = 'g';
    components[v] = comp_num;
    for (auto i = 0; i < adj_list_2[v].size(); i++) {
        int next_vert = adj_list_2[v][i];
        if (color[next_vert] == 'w') {
            dfs2(next_vert, comp_num);
        }
    }
}


int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list_1[x].push_back(y);
        adj_list_2[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 'w') {
            dfs1(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        color[i] = 'w';
    }
    int comp_num = 1;
    for (int i = 1; i <= n; i++) {
        int v = top[n-i];
        if (color[v] == 'w') {
            dfs2(v, comp_num);
            comp_num++;
        }
    }
    cout << comp_num - 1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << components[i] << " ";
    }


    return 0;
}
