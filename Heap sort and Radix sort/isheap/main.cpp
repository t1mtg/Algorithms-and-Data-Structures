#include <iostream>
using namespace std;
bool IsHeap(int a[], int N) {
    for (int i = 0; i < N/2; i++) {
        if ((2*i + 1 < N) && (a[i] > a[2*i + 1]) || (2*i + 2 < N) && (a[i] > a[2*i + 2])) {
            return 0;
        }
    }
    return 1;
};
int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if (IsHeap(a, N)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
 
    return 0;
}