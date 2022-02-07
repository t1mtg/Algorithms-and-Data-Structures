#include <iostream>
using namespace std;

int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int S, N;
    cin >> S >> N;
    int w[N];
    for (int i = 0; i < N; i++)
        cin >> w[i];
    int d[N+1][S + 1];
    for (int i = 0; i < N + 1; i++)
        d[i][0] = 0;
    for (int i = 0; i < S + 1; i++)
        d[0][i] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= S; j++)
            if (w[i-1] <= j)
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i - 1]] + w[i - 1]);
            else
                d[i][j] = d[i - 1][j];
    cout << d[N][S];
    return 0;
}
