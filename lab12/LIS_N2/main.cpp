#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    /*for (auto &i : a)
        cout << i << " ";*/
    int prev[n];
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dist[j] + 1 > dist[i]) {
                dist[i] = dist[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int length = dist[0];
    for (int i = 0; i < n; i++) {
        if (dist[i] > length) {
            pos = i;
            length = dist[i];
        }
    }

    vector <int> ans;
    while (pos != -1) {
        ans.push_back(a[pos]);
        pos = prev[pos];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int &i : ans)
        cout << i << " ";
    return 0;
}
