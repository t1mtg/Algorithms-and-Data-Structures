#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9 + 1

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    return l;
}

int main() {
    int n;
    cin >> n;
    vector <int> a;
    int length = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    /*for (auto &i : a)
        cout << i << " ";*/
    int prev[n];
    int dist[n + 1];
    int pos[n + 1];

    pos[0] = -1;
    dist[0] = -INF;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    for (int i = 0; i < n; i++) {
        int j = binarySearch(dist, 0, n, a[i]);
        //cout << j << endl;
        if (dist[j - 1] < a[i] && a[i] < dist[j])
            dist[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = max(length, j);
    }


    vector <int> ans;
    int p = pos[length];
    while (p != -1) {
        ans.push_back(a[p]);
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int &i : ans)
        cout << i << " ";
    return 0;
}
