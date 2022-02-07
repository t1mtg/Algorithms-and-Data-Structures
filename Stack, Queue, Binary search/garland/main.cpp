#include <iostream>
#include <fstream>
using namespace std;
int n;
const double eps = 10e-11;

double point_2(double a[]) {
    double left = 0;
    double right = a[0];
    while (right > left + eps) {
        a[1] = (left + right) / 2;
        bool flag = true;
        for (int i = 2; i < n; i++) {
            a[i] = 2 * a[i - 1] + 2 - a[i - 2];
            if (a[i] < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            right = a[1];
        } else {
            left = a[1];
        }
    }
    return a[n-1];
}

int main() {
    ifstream fin("garland.in");
    ofstream fout("garland.out");
    fin >> n;
    double a[n];
    fin >> a[0];
    printf("%.2lf", point_2(a));
    fin.close();
    fout.close();
    return 0;
}
