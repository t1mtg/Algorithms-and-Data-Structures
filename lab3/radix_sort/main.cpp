#include <iostream>
#include <vector>
using namespace std;

void radix_sort(vector <string> &a, int n, int m, int k) {
    vector<string> res;
    for (int phase = 0; phase < k; phase++) {
        res.clear();
        vector<vector<string>> count(26);
        int j = m - phase - 1;
        for (int i = 0; i < n; i++) {
            count[a[i][j] - 'a'].push_back(a[i]);
        }
        for (int i = 0; i < count.size(); i++) {
            for (int p = 0; p < count[i].size(); p++) {
                res.push_back(count[i][p]);
            }
        }
        a = res;
    }
}


int main() {
freopen("radixsort.in", "r", stdin);
freopen("radixsort.out", "w", stdout);
int n, m, k;
cin >> n >> m >> k;
vector <string> a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
radix_sort(a, n, m, k);
for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
}

    return 0;
}
