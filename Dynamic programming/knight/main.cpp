#include <iostream>
#include <vector>

using namespace std;

int knight(int i, int j, int n, int m, vector<vector<int>> &desk) {
    if (i >= 0 && j >= 0 && i < n && j < m) {
        if (desk[i][j] == 0) {
            if (i - 2 >= 0 && j - 1 >= 0)
                desk[i][j] += knight(i - 2, j - 1, n, m, desk);
            if (i - 2 >= 0 && j + 1 < m)
                desk[i][j] += knight(i - 2, j + 1, n, m, desk);
            if (i - 1 >= 0 && j - 2 >= 0)
                desk[i][j] += knight(i - 1, j - 2, n, m, desk);
            if (i + 1 < n  && j - 2 >= 0)
                desk[i][j] += knight(i + 1, j - 2, n, m, desk);
        }
    }
    return desk[i][j];
}

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> desk;
    for (int i = 0; i < n; i++) {
        desk.emplace_back();
        for (int j = 0; j < m; j++) {
            desk[i].push_back(0);
        }
    }
    desk[0][0] = 1;
    int s = knight(n - 1, m - 1, n, m, desk);
    cout << s;
    return 0;
}
