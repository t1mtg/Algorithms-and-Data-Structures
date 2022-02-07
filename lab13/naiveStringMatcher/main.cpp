#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    string p, t;
    cin >> p >> t;
    int n = t.length();
    int m = p.length();
    vector<int> ans;
    string temp;
    for (int i = 0; i < n - m + 1; i++) {
        temp.assign(t, i, p.length());
        if (temp == p) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << " ";
}
