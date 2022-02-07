#include <iostream>
using namespace std;
int main ()
{
    int i, j, n;
    float key;
    float M[10000];
    float K[10000];
    float n1,n2,n3;
    int m1,m2,m3;
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> M[i];
        K[i] = M[i];
    }

    for (i = 1; i < n; i++) {
        key = M[i];
        for (j = i - 1; j >= 0 && M[j] > key; j--) {
            M[j+1] = M[j];
        }
        M[j+1] = key;
    }
    n1 = M[0];
    n2 = M[n / 2];
    n3 = M[n-1];
    for (i = 0; i < n; i++) {
        if (K[i] == n1) {
            m1 = i + 1;
        }
        if (K[i] == n2) {
            m2 = i + 1;
        }
        if (K[i] == n3) {
            m3 = i + 1;
        }

    }
    cout << m1 << " " << m2 << " " << m3 << " " << endl;
    return 0;
}
