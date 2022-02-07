#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define INF 1000000000
using namespace std;

class Point {
public:
    int x, y;
};

int main() {
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    int n;
    cin >> n;
    vector <Point> vect(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> vect[i].x >> vect[i].y;
    }

    vector <vector <double>> g(n + 1, vector <double> (n + 1) );
    double s;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            s = sqrt(pow(vect[i].x - vect[j].x, 2) + pow(vect[i].y - vect[j].y, 2));
            g[i][j] = s;
            g[j][i] = s;
        }
        g[i][i] = INF;
    }

    vector<bool> used (n + 1, false);
    vector<double> min_e (n + 1, INF);
    min_e[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        used[v] = true;
        for (int j = 1; j <= n; ++j) {
            if (g[v][j] < min_e[j] && !used[j]) {
                min_e[j] = g[v][j];
            }
        }
    }

    double res = 0;
    for (int i = 1; i <= n; ++i) {
        res += min_e[i];
    }

    cout << setprecision(10) << res;

    return 0;
}