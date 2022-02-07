#include <iostream>
using namespace std;

void merge(int *a, int left, int right) {
    int *res = new int[10000];
    int pointer1, pointer2;
    pointer1 = left;
    pointer2 = (left + right) / 2 + 1;

    for (int j = left; j <= right; j++) {
        if ((pointer1 <= ((left + right) / 2)) && ((a[pointer1] < a[pointer2]) || (pointer2 > right))) {
            res[j] = a[pointer1];
            pointer1++;
        } else {
            res[j] = a[pointer2];
            pointer2++;
        }
    }
    for (int j = left; j <= right; j++) {
        a[j] = res[j];
    }
    delete[]res;
}

void merge_sort(int *a, int begin, int end) {
    if (begin < end) {
        merge_sort(a, begin, (begin + end)/2);
        merge_sort(a, (begin + end)/2 + 1, end);
        merge(a, begin, end);
    }
}


int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N;
    int *a = new int[10000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, N-1);
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    delete[]a;
    return 0;
}