#include <iostream>
using namespace std;
int main ()
{
    int i, j, n, key;
    int a[10000];
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}