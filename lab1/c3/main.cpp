#include <iostream>
using namespace std;
int main() {

    int h,w,i,j;
    int a[1000][1000];
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    cin >> h >> w;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    int il, jd;
    for (i = h - 1; i >= 0; i--) {
        for (j = 0; j < w; j++) {
            if (j == 0) {
                il = 0;
            } else {
                il = a[i][j-1];
            }
            if (i == h - 1) {
                jd = 0;
            } else {
                jd = a[i+1][j];
            }
            if (jd > il) {
                a[i][j] += jd;
            } else {
                a[i][j] += il;
            }
        }
    }

    cout << a[0][w-1];
    return 0;
}
