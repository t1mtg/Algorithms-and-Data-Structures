#include <iostream>
#include <fstream>
using namespace std;
int n;

int bin_search_left(int a[], int x) {
    int l = -1;
    int r = n;
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r < n && a[r] == x) {
        return r + 1;
    } else {
        return -1;
    }
}

int bin_search_right(int a[], int x) {
    int l = -1;
    int r = n;
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r <= n && a[r - 1] == x) {
        return r;
    } else {
        return -1;
    }
}

int main() {
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");
    fin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    int m;
    fin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        fin >> x;
        fout << bin_search_left(a, x) << " ";
        fout << bin_search_right(a, x) << endl;
    }
    fin.close();
    fout.close();
    return 0;
}