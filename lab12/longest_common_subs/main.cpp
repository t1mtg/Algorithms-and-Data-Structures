#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    string s1, s2;
    cin >> s1;
    int n = s1.length();
    s1 = " " + s1;
    cin >> s2;
    int m = s2.length();
    s2 = " " + s2;
    int d[n+1][m+1];
    for (int i = 0; i <= n; i++)
        d[i][0] = 0;
    for (int i = 0; i <= m; i++)
        d[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    string ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i] == s2[j]) {
            ans += s1[i];
            i--;
            j--;
        } else if (d[i - 1][j] > d[i][j - 1]) {
            i--;
        } else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
