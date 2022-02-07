#include <iostream>
using namespace std;
int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    bool IsHeap = true;
    for (int i = 0; i < N / 2; i++) {
        if ((2 * i + 1 < N) && (a[i] > a[2 * i + 1])) {
            IsHeap = false;
        }
        if ((2 * i + 2 < N) && (a[i] > a[2 * i + 2])) {
            IsHeap = false;
        }
    }
    cout << ((IsHeap) ? "YES" : "NO");
    return 0;
}

